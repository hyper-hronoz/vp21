#include "EmployerView.h"

#include "../Controllers/EmployerController.h"
#include "../Models/EmployerModel.h"

void EmployerView::display() {
    this->createEmployerMenu();
    this->menu->awaitUserInput();
}

void EmployerView::createEmployerMenu() {
    this->menu->setTitle("--Меню сотрудника--");

    menu->append(menuItemFactory->create("Войти как сотрудник", [this]() {
        // EmployerModel *employerModel = new EmployerModel();
        //
        // employerModel->setLogin("hronoz employer")->setPassword("7878488")->setName("Vladislav empl")->setSername("Moryakov empl");
        //
        // employerModel->signUp();
        //
        // delete employerModel;
    }));

    menu->append(menuItemFactory->create("Вернуться в клавное меню", [this]() {
        this->controller->getInstance<EmployerController>()->goMain();
    }));
}
