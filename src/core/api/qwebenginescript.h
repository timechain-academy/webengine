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

#ifndef QWEBENGINESCRIPT_H
#define QWEBENGINESCRIPT_H

#include <QtWebEngineCore/qtwebenginecoreglobal.h>
#include <QtCore/qurl.h>
#include <QtCore/qobject.h>
#include <QtCore/qshareddata.h>

namespace QtWebEngineCore {
class UserScript;
} // namespace

QT_BEGIN_NAMESPACE

class Q_WEBENGINECORE_EXPORT QWebEngineScript
{

    Q_GADGET
    Q_PROPERTY(QString name READ name WRITE setName FINAL)
    Q_PROPERTY(QUrl sourceUrl READ sourceUrl WRITE setSourceUrl FINAL)
    Q_PROPERTY(QString sourceCode READ sourceCode WRITE setSourceCode FINAL)
    Q_PROPERTY(InjectionPoint injectionPoint READ injectionPoint WRITE setInjectionPoint FINAL)
    Q_PROPERTY(quint32 worldId READ worldId WRITE setWorldId FINAL)
    Q_PROPERTY(bool runsOnSubFrames READ runsOnSubFrames WRITE setRunsOnSubFrames FINAL)

public:

    enum InjectionPoint {
        Deferred,
        DocumentReady,
        DocumentCreation
    };

    Q_ENUM(InjectionPoint)

    enum ScriptWorldId {
        MainWorld = 0,
        ApplicationWorld,
        UserWorld
    };

    Q_ENUM(ScriptWorldId)

    QWebEngineScript();
    QWebEngineScript(const QWebEngineScript &other);
    ~QWebEngineScript();

    QWebEngineScript &operator=(const QWebEngineScript &other);

    QString name() const;
    void setName(const QString &);

    QUrl sourceUrl() const;
    void setSourceUrl(const QUrl &url);

    QString sourceCode() const;
    void setSourceCode(const QString &);

    InjectionPoint injectionPoint() const;
    void setInjectionPoint(InjectionPoint);

    quint32 worldId() const;
    void setWorldId(quint32);

    bool runsOnSubFrames() const;
    void setRunsOnSubFrames(bool on);

    bool operator==(const QWebEngineScript &other) const;
    inline bool operator!=(const QWebEngineScript &other) const
    { return !operator==(other); }
    void swap(QWebEngineScript &other) noexcept { d.swap(other.d); }

private:
    friend class QWebEngineScriptCollectionPrivate;
    QWebEngineScript(const QtWebEngineCore::UserScript &);

    QSharedDataPointer<QtWebEngineCore::UserScript> d;
};

Q_DECLARE_TYPEINFO(QWebEngineScript, Q_RELOCATABLE_TYPE);

#ifndef QT_NO_DEBUG_STREAM
Q_WEBENGINECORE_EXPORT QDebug operator<<(QDebug, const QWebEngineScript &);
#endif

QT_END_NAMESPACE

#endif // QWEBENGINESCRIPT_H
