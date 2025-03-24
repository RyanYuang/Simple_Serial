//
// Created by Yuang Ryan on 2025/2/26.
//

#include "Drage_Widget.h"
#include "QMouseEvent"


Drage_Widget::Drage_Widget(QWidget *parent) : QPushButton(parent)
{

    isPressed = false;
    is_Moved = false;
    lastPoint = QPoint();
    x_left_distance = 0;
    x_right_distance =0;
    y_top_distance =0;
    y_bottom_distance=0;

    this->installEventFilter(this);
}

Drage_Widget::~Drage_Widget()
{

}

void Drage_Widget::setMargin(int left,int top,int right, int bottom)
{
    x_left_distance = left;
    y_top_distance = top;
    x_right_distance = right;
    y_bottom_distance = bottom;
}

bool Drage_Widget::eventFilter(QObject *watched, QEvent *event)
{
    QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
    switch(event->type())
    {
        case QEvent::MouseButtonPress:
        {
            // 按钮按下，设置此时的状态是按下的，在鼠标移动的时候才会出发按钮移动事件
            if(mouseEvent->button() == Qt::LeftButton)
            {
                lastPoint = mouseEvent->pos();  //记录按下瞬间鼠标的坐标
                isPressed = true;
            }
            break;
        }
        case QEvent::MouseMove:
        {
            //左键按下，可以判断移动按钮
            if(isPressed)
            {
                //得到距离差
                int dx = mouseEvent->pos().x() - lastPoint.x();
                int dy = mouseEvent->pos().y() - lastPoint.y();
                int x1 = this->x() + dx;
                int y1 = this->y() + dy;
                //int right_distance = this.
                this->move(this->x()+dx, this->y()+dy);
                is_Moved = true;
            }
            break;
        }
        case QEvent::MouseButtonRelease:
        {
            if(is_Moved !=true){
                emit clicked();
                emit toggled(!isChecked);
                isChecked = !isChecked;
            }else{
                is_Moved = false;
            }
            isPressed = false;
            break;
        }
        case QEvent::MouseButtonDblClick:
            emit doubleClicked();
            break;
        default:
            break;
    }
    return QWidget::eventFilter(watched,event);
}