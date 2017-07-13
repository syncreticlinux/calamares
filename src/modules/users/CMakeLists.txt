find_package(ECM 5.10.0 NO_MODULE)
if( ECM_FOUND )
    set(CMAKE_MODULE_PATH ${ECM_MODULE_PATH} ${CMAKE_MODULE_PATH})
    include( ECMAddTests )
endif()

find_package( Qt5 COMPONENTS Core Test REQUIRED )
find_package( Crypt )

include_directories( ${PROJECT_BINARY_DIR}/src/libcalamaresui )

calamares_add_plugin( users
    TYPE viewmodule
    EXPORT_MACRO PLUGINDLLEXPORT_PRO
    SOURCES
        jobs/CreateUserJob.cpp
        jobs/SetPasswordJob.cpp
        UsersViewStep.cpp
        gui/UsersPage.cpp
        jobs/SetHostNameJob.cpp
        jobs/SetAvatarJob.cpp
        gui/AddUserDialog.cpp
    UI
        gui/page_usersetup.ui
        gui/adduserdialog.ui
    RESOURCES
        users.qrc
    LINK_PRIVATE_LIBRARIES
        calamaresui
        ${CRYPT_LIBRARIES}
    SHARED_LIB
)

if( ECM_FOUND )
    ecm_add_test(
            PasswordTests.cpp
            jobs/SetPasswordJob.cpp
        TEST_NAME
            passwordtest
        LINK_LIBRARIES
            ${CALAMARES_LIBRARIES}
            Qt5::Core
            Qt5::Test
            ${CRYPT_LIBRARIES}
    )
    set_target_properties( passwordtest PROPERTIES AUTOMOC TRUE )
endif()
