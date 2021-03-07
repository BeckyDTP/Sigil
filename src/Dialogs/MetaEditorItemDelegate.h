/************************************************************************
**
**  Copyright (C) 2021      Kevin B. Hendricks, Stratford Ontario Canada
**  Copyright (C) 2011-2012 John Schember <john@nachtimwald.com>
**  Copyright (C) 2012      Dave Heiland
**  Copyright (C) 2009-2011 Strahinja Markovic  <strahinja.markovic@gmail.com>
**
**  This file is part of Sigil.
**
**  Sigil is free software: you can redistribute it and/or modify
**  it under the terms of the GNU General Public License as published by
**  the Free Software Foundation, either version 3 of the License, or
**  (at your option) any later version.
**
**  Sigil is distributed in the hope that it will be useful,
**  but WITHOUT ANY WARRANTY; without even the implied warranty of
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**  GNU General Public License for more details.
**
**  You should have received a copy of the GNU General Public License
**  along with Sigil.  If not, see <http://www.gnu.org/licenses/>.
**
*************************************************************************/

#pragma once
#ifndef METADATAITEMDELEGATE_H
#define METADATAITEMDELEGATE_H

#include <QString>
#include <QStringList>
#include <QHash>

#include <QtWidgets/QStyledItemDelegate>

class MetaEditorItemDelegate : public QStyledItemDelegate
{
    Q_OBJECT

public:
    MetaEditorItemDelegate(QObject *parent = 0);
    ~MetaEditorItemDelegate();

    void setChoices(const QHash<QString, QStringList>& choices) { m_Choices = choices; };
    
    virtual QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    virtual void setEditorData(QWidget *editor, const QModelIndex &index) const;
    virtual void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
    virtual void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    virtual QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;

private:
    QHash<QString, QStringList> m_Choices;
};


#endif // METADATAITEMDELEGATE_H
