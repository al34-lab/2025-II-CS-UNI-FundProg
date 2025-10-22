// Mismo código funciona en Windows y Mac
#include <QApplication>
#include <QMainWindow>
#include <QPushButton>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    
    QMainWindow window;
    QPushButton button("Hola desde Windows y Mac!", &window);
    
    window.show();
    return app.exec();
}