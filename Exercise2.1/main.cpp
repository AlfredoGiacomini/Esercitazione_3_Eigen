#include <iostream>
#include <iomanip>
#include "Eigen/Eigen"
#include "Eigen/Dense"

using namespace std;
using namespace Eigen;


Vector2d PALU (const Matrix2d& A, const Vector2d& b)
{
    PartialPivLU<Matrix2d> lu(A);
    return lu.solve(b);
}
Vector2d QR (const Matrix2d& A, const Vector2d& b)
{
    ColPivHouseholderQR<Matrix2d> qr(A);
    return qr.solve(b);
}
double errore_relativo(const Vector2d x_calcolato,const Vector2d x_esatto)
{
    return (x_calcolato - x_esatto).norm() / x_esatto.norm();
}
int main()
{
    Matrix2d A1 , A2, A3;
    A1 << 5.547001962252291e-01, -3.770900990025203e-02,
          8.320502943378437e-01, -9.992887623566787e-01;
    A2 << 5.547001962252291e-01, -5.540607316466765e-01,
          8.320502943378437e-01, -8.324762492991313e-01;
    A3 << 5.547001962252291e-01, -5.547001955851905e-01,
          8.320502943378437e-01, -8.320502947645361e-01;
    Vector2d b1, b2, b3, xsol ,x1_PALU, x2_PALU, x3_PALU, x1_qr, x2_qr, x3_qr;
    b1 << -5.169911863249772e-01,
           1.672384680188350e-01;
    b2 << -6.394645785530173e-04,
           4.259549612877223e-04;
    b3 << -6.400391328043042e-10,
           4.266924591433963e-10;
    xsol << -1.0, -1.0;
    cout << scientific << setprecision(15);
    cout << "gli errori relativi PALU sono" << endl;
    x1_PALU=PALU(A1, b1);
    x2_PALU=PALU(A2, b2);
    x3_PALU=PALU(A3, b3);
    cout << "errore relativo x1 = " << errore_relativo(x1_PALU, xsol) << endl;
    cout << "errore relativo x2 = " << errore_relativo(x2_PALU, xsol) << endl;
    cout << "errore relativo x3 = " << errore_relativo(x3_PALU, xsol) << endl;
    x1_qr=QR(A1, b1);
    x2_qr=QR(A2, b2);
    x3_qr=QR(A3, b3);
    cout << "errore relativo x1 = " << errore_relativo(x1_qr, xsol) << endl;
    cout << "errore relativo x2 = " << errore_relativo(x2_qr, xsol) << endl;
    cout << "errore relativo x3 = " << errore_relativo(x3_qr, xsol) << endl;
    cout << "fine esequzione programma " << endl;
        return 0;
        
}



