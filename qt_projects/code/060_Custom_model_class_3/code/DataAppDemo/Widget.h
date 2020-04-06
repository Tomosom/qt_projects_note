#ifndef WIDGET_H
#define WIDGET_H

#include <QtGui/QWidget>
#include <QTableView>
#include <QPushButton>
#include <QMenu>
#include "ScoreInfoModel.h"

class Widget : public QWidget
{
    Q_OBJECT
    
    ScoreInfoModel m_model;
    QTableView m_view;
    QPushButton m_refreshBtn;
    QPushButton m_clearBtn;
    QPushButton m_scoreBtn;
    QMenu m_menu;
private slots:
    void onRefreshBtnClicked();
    void onClearBtnClicked();
    void onScoreBtnClicked();
    void onDeleteActionClicked();
public:
    Widget(QWidget* parent = 0);
    bool eventFilter(QObject* obj, QEvent* evt);
    ~Widget();
};

#endif // WIDGET_H
