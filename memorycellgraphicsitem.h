// File: memorycellgraphicsitem.h
/*
    Pep8-1 is a virtual machine for writing machine language and assembly
    language programs.

    Copyright (C) 2009  J. Stanley Warford, Pepperdine University

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef MEMORYCELLGRAPHICSITEM_H
#define MEMORYCELLGRAPHICSITEM_H

#include <QGraphicsItem>

class MemoryCellGraphicsItem : public QGraphicsItem
{
public:
    MemoryCellGraphicsItem(int addr, int val, QString sym);
    ~MemoryCellGraphicsItem() { }

    QRectF boundingRect() const;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    int address;
    int value;
    QString symbol;
    QRectF box;
    QColor boxColor;
    QColor boxBgColor;
    QColor textColor;

};

#endif // MEMORYCELLGRAPHICSITEM_H
