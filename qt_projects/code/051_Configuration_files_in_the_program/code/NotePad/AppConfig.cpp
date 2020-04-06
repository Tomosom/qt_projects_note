#include "AppConfig.h"
#include <QFile>
#include <QDataStream>
#include <QApplication>

AppConfig::AppConfig(QObject* parent) : QObject(parent)
{
    m_isValid = restore();
}

AppConfig::AppConfig(QFont font, bool isWrap, bool tbVisible, bool sbVisible, QObject* parent)
{
    m_editorFont = font;
    m_isAutoWrap = isWrap;
    m_isToolBarVisible = tbVisible;
    m_isStatusBarVisible = sbVisible;
    m_isValid = true;
}

bool AppConfig::restore()
{
    bool ret = true;
    QFile file(QApplication::applicationDirPath() + "/app.config");

    if( file.open(QIODevice::ReadOnly) )
    {
        QDataStream in(&file);

        in.setVersion(QDataStream::Qt_4_7);

        in >> m_editorFont;
        in >> m_isAutoWrap;
        in >> m_isToolBarVisible;
        in >> m_isStatusBarVisible;

        file.close();
    }
    else
    {
        ret = false;
    }

    return ret;
}

bool AppConfig::store()
{
    bool ret = true;
    QFile file(QApplication::applicationDirPath() + "/app.config");

    if( file.open(QIODevice::WriteOnly) )
    {
        QDataStream out(&file);

        out.setVersion(QDataStream::Qt_4_7);

        out << m_editorFont;
        out << m_isAutoWrap;
        out << m_isToolBarVisible;
        out << m_isStatusBarVisible;

        file.close();
    }
    else
    {
        ret = false;
    }

    return ret;
}

QFont AppConfig::editorFont()
{
    return m_editorFont;
}

bool AppConfig::isAutoWrap()
{
    return m_isAutoWrap;
}

bool AppConfig::isToolBarVisible()
{
    return m_isToolBarVisible;
}

bool AppConfig::isStatusBarVisible()
{
    return m_isStatusBarVisible;
}

bool AppConfig::isValid()
{
    return m_isValid;
}
