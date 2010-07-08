/****************************************************************************
**
** Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the QtSparql module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial Usage
** Licensees holding valid Qt Commercial licenses may use this file in
** accordance with the Qt Commercial License Agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Nokia.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights.  These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
** If you have questions regarding the use of this file, please contact
** Nokia at qt-info@nokia.com.
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QSPARQLQUERY_H
#define QSPARQLQUERY_H

#include <QtSparql/qsparql.h>

#include <QtCore/qstring.h>

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE

QT_MODULE(Sparql)

class QVariant;
template <class Key, class T> class QMap;
class QSparqlResultRow;
class QSparqlBinding;
class QSparqlQueryPrivate;

class Q_SPARQL_EXPORT QSparqlQuery
{
public:
    enum StatementType { SelectStatement, AskStatement, ConstructStatement,
                         UpdateStatement, InsertStatement, DeleteStatement };
    explicit QSparqlQuery(const QString& query = QString(),
                          StatementType type = SelectStatement);
    QSparqlQuery(const QSparqlQuery& other);
    QSparqlQuery& operator=(const QSparqlQuery& other);
    ~QSparqlQuery();

    StatementType type() const;
    void setType(StatementType type);

    QString query() const;
    void setQuery(const QString& query);

    void bindValue(const QString& placeholder, const QVariant& val);
    void bindValue(const QSparqlBinding& binding);
    void bindValues(const QSparqlResultRow& bindings);
    QVariant boundValue(const QString& placeholder) const;
    QMap<QString, QVariant> boundValues() const;
    void unbindValues();

    QString preparedQueryText() const;

private:
    QSparqlQueryPrivate* d;
};

QT_END_NAMESPACE

QT_END_HEADER

#endif // QSPARQLQUERY_H
