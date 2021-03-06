/****************************************************************************
**
** Copyright (C) 2009 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the QtTest module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** No Commercial Usage
** This file contains pre-release code and may not be distributed.
** You may use this file in accordance with the terms and conditions
** contained in the Technology Preview License Agreement accompanying
** this package.
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
** If you have questions regarding the use of this file, please contact
** Nokia at qt-info@nokia.com.
**
**
**
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "QtTest/private/qbenchmarkmeasurement_p.h"
#include "QtTest/private/qbenchmark_p.h"
#include <qdebug.h>

QT_BEGIN_NAMESPACE

// QBenchmarkTimeMeasurer implementation

void QBenchmarkTimeMeasurer::start()
{
    time.start();
}

qint64 QBenchmarkTimeMeasurer::checkpoint()
{
    return time.elapsed();
}

qint64 QBenchmarkTimeMeasurer::stop()
{	
    return time.elapsed();
}

bool QBenchmarkTimeMeasurer::isMeasurementAccepted(qint64 measurement)
{
    return (measurement > 20);
}

int QBenchmarkTimeMeasurer::adjustIterationCount(int suggestion)
{ 
    return suggestion; 
}

int QBenchmarkTimeMeasurer::adjustMedianCount(int)
{ 
    return 1; 
}

QString QBenchmarkTimeMeasurer::unitText()
{
    return QLatin1String("msec");
}

QString QBenchmarkTimeMeasurer::metricText()
{
    return QLatin1String("walltime");
}

#ifdef HAVE_TICK_COUNTER // defined in 3rdparty/cycle_p.h

void QBenchmarkTickMeasurer::start()
{
    startTicks = getticks();
}

qint64 QBenchmarkTickMeasurer::checkpoint()
{
    CycleCounterTicks now = getticks();
    return qRound64(elapsed(now, startTicks));
}

qint64 QBenchmarkTickMeasurer::stop()
{
    CycleCounterTicks now = getticks();
    return qRound64(elapsed(now, startTicks));
}

bool QBenchmarkTickMeasurer::isMeasurementAccepted(qint64)
{
    return true;
}

int QBenchmarkTickMeasurer::adjustIterationCount(int)
{ 
    return 1; 
}

int QBenchmarkTickMeasurer::adjustMedianCount(int)
{ 
    return 1; 
}

bool QBenchmarkTickMeasurer::needsWarmupIteration()
{ 
    return true; 
}

QString QBenchmarkTickMeasurer::unitText()
{
    return QLatin1String("ticks");
}

QString QBenchmarkTickMeasurer::metricText()
{
    return QLatin1String("cputicks");
}

#endif


QT_END_NAMESPACE
