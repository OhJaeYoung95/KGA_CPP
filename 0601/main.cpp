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
    // 직원관리를 목적으로 설계된 컨트롤 클래스의 객체생성
    EmployeeHandler handler;

    ForeignSalesWorker* fseller1 = new ForeignSalesWorker("Hong", 1000, 0.1, RISK_LEVEL::RISK_A);
    fseller1->AddSalesResult(7000); // 영업실적 7000
    handler.AddEmployee(fseller1);


    ForeignSalesWorker* fseller2 = new ForeignSalesWorker("Yoon", 1000, 0.1, RISK_LEVEL::RISK_B);
    fseller2->AddSalesResult(7000); // 영업실적 7000
    handler.AddEmployee(fseller2);

    ForeignSalesWorker* fseller3 = new ForeignSalesWorker("Lee", 1000, 0.1, RISK_LEVEL::RISK_C);
    fseller3->AddSalesResult(7000); // 영업실적 7000
    handler.AddEmployee(fseller3);

    // 이번 달에 지불해야 할 급여의 정보
    handler.ShowAllSalaryInfo();
    return 0;
}