#pragma once

#include <common.h>
#include <navigationmenu.h>
#include <dao/user_dao.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();

    private:
        Ui::MainWindow *ui;

        QPoint mouse_cur_pos;
        QPoint mouse_new_pos;

        Navigationmenu *navigation_menu;

        CXX_ISRS::Config config;

        UserDAO *user_dao;

        void load_configuration();

        void throw_popup(CXX_ISRS::LoginException &);

        void show_popup(uint8_t, uint8_t, uint8_t);

        void clear_interface();

    signals:
        void fade_in_signal();

        void fade_out_signal();

    private slots:
        void on_quit_button_clicked();

        void on_minimize_button_clicked();

        void mousePressEvent(QMouseEvent *mouse_press_event);

        void mouseMoveEvent(QMouseEvent *mouse_move_event);

        void on_login_button_clicked();

        void back_to_login_slot();

        void fade_in_slot();

        void fade_out_slot();

        void fade_delay_slot();
};
