/****************************************************************************
**
** Copyright (C) 2020 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the QtWebEngine module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:GPL-EXCEPT$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3 as published by the Free Software
** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-3.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

import QtQuick 2.0
import QtTest 1.0
import QtWebEngine 1.4

TestWebEngineView {
    id: view
    width: 400
    height: 400

    SignalSpy {
        id: spy
        target: view
        signalName: "audioMutedChanged"
    }

    TestCase {
        id: test
        name: "WebEngineViewAudioMuted"

        function test_audioMuted() {
            compare(view.audioMuted, false);
            view.audioMuted = true;
            view.url = "about:blank";
            verify(view.waitForLoadSucceeded());
            compare(view.audioMuted, true);
            compare(spy.count, 1);
            compare(spy.signalArguments[0][0], true);
            view.audioMuted = false;
            compare(view.audioMuted, false);
            compare(spy.count, 2);
            compare(spy.signalArguments[1][0], false);
        }
    }
}

