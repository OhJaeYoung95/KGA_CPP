#include <iostream>
#include <cstring>
#include "Employee.h"
#include "EmployeeHandler.h"
#include "PermanentWorker.h"
#include "SalesWorker.h"
#include "TemporaryWorker.h"
#include "ForeignSaleWorker.h"

using namespace std;


int main(void)
{
    // ���������� �������� ����� ��Ʈ�� Ŭ������ ��ü����
    EmployeeHandler handler;

    ForeignSalesWorker* fseller1 = new ForeignSalesWorker("Hong", 1000, 0.1, RISK_LEVEL::RISK_A);
    fseller1->AddSalesResult(7000); // �������� 7000
    handler.AddEmployee(fseller1);


    ForeignSalesWorker* fseller2 = new ForeignSalesWorker("Yoon", 1000, 0.1, RISK_LEVEL::RISK_B);
    fseller2->AddSalesResult(7000); // �������� 7000
    handler.AddEmployee(fseller2);

    ForeignSalesWorker* fseller3 = new ForeignSalesWorker("Lee", 1000, 0.1, RISK_LEVEL::RISK_C);
    fseller3->AddSalesResult(7000); // �������� 7000
    handler.AddEmployee(fseller3);

    // �̹� �޿� �����ؾ� �� �޿��� ����
    handler.ShowAllSalaryInfo();
    return 0;
}