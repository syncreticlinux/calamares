/* === This file is part of Calamares - <https://github.com/calamares> ===
 *
 *   Copyright 2014-2015, Teo Mrnjavac <teo@kde.org>
 *   Copyright 2019, Adriaan de Groot <groot@kde.org>
 *
 *   Calamares is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   Calamares is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with Calamares. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef CHECKER_RESULTSLISTWIDGET_H
#define CHECKER_RESULTSLISTWIDGET_H

#include "modulesystem/Requirement.h"

#include <QBoxLayout>
#include <QWidget>

class ResultsListWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ResultsListWidget( QWidget* parent = nullptr );

    void init( const Calamares::RequirementsList& checkEntries );

private:
    void showDetailsDialog( const Calamares::RequirementsList& checkEntries );

    QBoxLayout* m_mainLayout;
    QBoxLayout* m_entriesLayout;
    int m_paddingSize;
};

#endif // CHECKER_RESULTSLISTWIDGET_H
