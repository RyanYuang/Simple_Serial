//
// Created by Yuang Ryan on 2025/2/26.
//

#ifndef SIMPLE_SERIALL_DRAGE_WIDGET_H
#define SIMPLE_SERIALL_DRAGE_WIDGET_H

#include "QString"
#include "QPoint"
#include "QWidget"
#include "QEvent"
#include "QPushButton"

class Drage_Widget: public QPushButton{
    Q_OBJECT
public:
    explicit Drage_Widget(QWidget *parent = NULL);
    ~Drage_Widget();
    void setMargin(int left,int top,int right, int bottom);
signals:
    void clicked();
    void doubleClicked();
    void toggled(bool isToggled);
protected:
    bool eventFilter(QObject* watched,QEvent *event);

private:
    QString text;           //显示文字
    bool isPressed;         //鼠标是否按下
    QPoint lastPoint;       //鼠标按下最后坐标
    bool is_Moved;          //是否正在移动
    int x_left_distance;    //可移动的距离左侧的距离
    int y_top_distance;     //可移动的距离上面的距离
    int x_right_distance;   //可移动的距离右侧的距离
    int y_bottom_distance;  //可移动的距离底部的距离
    bool isChecked =false;          //按钮的选中状态
};




#endif //SIMPLE_SERIALL_DRAGE_WIDGET_H
