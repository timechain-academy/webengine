/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the QtWebEngine module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 3 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL3 included in the
** packaging of this file. Please review the following information to
** ensure the GNU Lesser General Public License version 3 requirements
** will be met: https://www.gnu.org/licenses/lgpl-3.0.html.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 2.0 or (at your option) the GNU General
** Public license version 3 or any later version approved by the KDE Free
** Qt Foundation. The licenses are as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-2.0.html and
** https://www.gnu.org/licenses/gpl-3.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QQUICKWEBENGINEFAVICONPROVIDER_P_P_H
#define QQUICKWEBENGINEFAVICONPROVIDER_P_P_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

#include <QtWebEngineQuick/private/qtwebengineglobal_p.h>
#include <QtQuick/QQuickImageProvider>

#include <QtCore/QMap>

QT_BEGIN_NAMESPACE

class QQuickWebEngineView;

class Q_WEBENGINE_PRIVATE_EXPORT QQuickWebEngineFaviconProvider : public QQuickImageProvider {
public:
    static QString identifier();
    static QUrl faviconProviderUrl(const QUrl &);

    QQuickWebEngineFaviconProvider();
    ~QQuickWebEngineFaviconProvider();

    QUrl attach(QQuickWebEngineView *, const QUrl &);
    void detach(QQuickWebEngineView *);


    QPixmap requestPixmap(const QString &, QSize *, const QSize &) override;

private:
    QQuickWebEngineView *viewForIconUrl(const QUrl &) const;
    QSize findFitSize(const QList<QSize> &, const QSize &, const QSize &) const;

    QMap<QQuickWebEngineView *, QList<QUrl> *> m_iconUrlMap;
    QQuickWebEngineView *m_latestView;
};

QT_END_NAMESPACE

#endif // QQUICKWEBENGINEFAVICONPROVIDER_P_P_H