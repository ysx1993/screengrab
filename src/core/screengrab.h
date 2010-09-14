/***************************************************************************
 *   Copyright (C) 2009 by Artem 'DOOMer' Galichkin                        *
 *   doomer3d@gmail.com                                                    *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
#ifndef SCREENGRAB_H
#define SCREENGRAB_H

#ifndef STR_PROC
#define STR_PROC "screengrab-qt"
#endif

#include "src/ui/mainwindow.h"

#include "src/core/config.h"
#include "src/core/regionselect.h"

#include <QtCore/QObject>
#include <QtGui/QPixmap>
#include <QtGui/QClipboard>
#include <QtCore/QTime>

#ifdef Q_WS_X11
#include <QtGui/QX11Info>
#endif

#include <QDebug>

class screengrab : public QObject
{
    Q_OBJECT

public Q_SLOTS:
    void slotQuit();
//     bool getScreen();
    void screenShot();

public:
    static screengrab* instance();
    ~screengrab();

    static QString getVersionPrintable();

    QPixmap getPixmap();

    bool writeScreen(QString& fileName, QString& format);
    void copyScreen();
    void autoSave();

    QString getSaveFilePath(QString format);
    QString getDateTimeFileName();
    Config *conf;

Q_SIGNALS:
    void newScreenShot(QPixmap *pixmap);

//private Q_SLOTS:

private:
    screengrab();
    screengrab(const screengrab &);
    screengrab& operator=(const screengrab &);

    static screengrab *corePtr;

    // functions
#ifdef Q_WS_WIN
    void getActiveWind_Win32();
#endif
#ifdef Q_WS_X11
    void getActiveWind_X11();
#endif

    // vars
    QPixmap *pixelMap; // pixel map

    bool hided;
    int scrNum; // screen num in session

};

#endif // SCREENGRAB_H
