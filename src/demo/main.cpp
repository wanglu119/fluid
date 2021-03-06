/*
 * This file is part of Fluid.
 *
 * Copyright (C) 2018 Pier Luigi Fiorini <pierluigi.fiorini@gmail.com>
 * Copyright (C) 2018 Michael Spencer <sonrisesoftware@gmail.com>
 *
 * $BEGIN_LICENSE:MPL2$
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * $END_LICENSE$
 */

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickStyle>
#include <QQmlContext>

#include "iconcategorymodel.h"
#include "iconnamemodel.h"

int main(int argc, char *argv[])
{
    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QQuickStyle::setStyle(QLatin1String("Material"));

    QGuiApplication app(argc, argv);
    app.setDesktopFileName(QLatin1String("io.liri.Fluid.Demo.desktop"));
    app.setQuitOnLastWindowClosed(true);

    // @uri Fluid.Demo
    qmlRegisterType<IconCategoryModel>("Fluid.Demo", 1, 0, "IconCategoryModel");
    qmlRegisterType<IconNameModel>("Fluid.Demo", 1, 0, "IconNameModel");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QLatin1String("qrc:/qml/main.qml")));

    return app.exec();
}
