#include <bits/stdc++.h>

using namespace std;

int polynome_value(vector<int> &polynome, int x) {
  int x1 = 1;
  int value = 0;
  for (int i = 0; i < polynome.size(); ++i) {
    value += x1 * polynome[i];
    x1 *= x;
  }
  return value;
}

int main() {
  cout << "Гыгыгы, программка для решение дз по алгебре от "
          "\x1b[31mДемченко\x1b[0m\n\n\n";
  cout << "Нажмите \x1b[32menter\x1b[0m, чтобы начать. Введите "
          "\x1b[31m\"end\"\x1b[0m "
          "и "
          "нажмите \x1b[32menter\x1b[0m, чтобы завершить выполнение: ";
  string s;
  getline(cin, s);
  if (s == "end") {
    return 1;
  }
  cout << endl;
  vector<int> polynom;
  for (int i = 0; i < 8; ++i) {
    printf("Введите коэффициент при x в степени %d: ", i);
    int k;
    cin >> k;
    cout << endl;
    polynom.push_back(k);
  }
  cout
      << "\nТеперь введите \x1b[31m!!!ЧЕТЫРЕ!!!\x1b[0m узловые точки.\n\n"
      << "Важно, чтобы \x1b[31mрасстояние между соседними точками было равно "
         "1\x1b[0m, а точки были расположены \x1b[31mпо возрастанию\x1b[0m.\n\n"
      << "\x1b[33mВ противном случае получится ХУЙНЯ, за которую я "
         "\x1b[31m!!!НЕ!!!\x1b[33m несу "
         "ответственность(((\x1b[0m\n\n";

  vector<int> x;
  for (int i = 0; i < 4; ++i) {
    cout << "Введите точку номер " << i + 1 << ": ";
    int k;
    cin >> k;
    x.push_back(k);
  }

  cout << "\n\n";
  vector<int> y0;
  vector<int> y1;
  vector<int> y2;
  vector<int> y3;

  for (int i = -abs(polynome_value(polynom, x[0]));
       i <= abs(polynome_value(polynom, x[0])); ++i) {
    if (i != 0 && polynome_value(polynom, x[0]) % i == 0) {
      y0.push_back(i);
    }
  }

  for (int i = -abs(polynome_value(polynom, x[1]));
       i <= abs(polynome_value(polynom, x[1])); ++i) {
    if (i != 0 && polynome_value(polynom, x[1]) % i == 0) {
      y1.push_back(i);
    }
  }

  for (int i = -abs(polynome_value(polynom, x[2]));
       i <= abs(polynome_value(polynom, x[2])); ++i) {
    if (i != 0 && polynome_value(polynom, x[2]) % i == 0) {
      y2.push_back(i);
    }
  }

  for (int i = -abs(polynome_value(polynom, x[3]));
       i <= abs(polynome_value(polynom, x[3])); ++i) {
    if (i != 0 && polynome_value(polynom, x[3]) % i == 0) {
      y3.push_back(i);
    }
  }

  cout << "Подходящая комбинация будет выделена \x1b[32mзеленым\x1b[0m цветом "
       << "\n\n";
  vector<int> wPolynome;
  cout << "Теперь введите коэффициенты многочлена, который вам выдал "
          "вольфрам\n\n";
  vector<int> wPolynom;
  for (int i = 0; i < 4; ++i) {
    printf("Введите коэффициент при x в степени %d: ", i);
    int k;
    cin >> k;
    wPolynom.push_back(k);
    cout << "\n" << "\n";
  }

  int d = 0;
  for (int i = 0; i < y0.size(); ++i) {
    for (int j = 0; j < y1.size(); ++j) {
      for (int k = 0; k < y2.size(); ++k) {
        for (int l = 0; l < y3.size(); ++l) {
          vector<int> a;
          vector<int> coeffs;
          a.push_back(y0[i]);
          a.push_back(y1[j] - y0[i]);
          a.push_back((y2[k] - 2 * y1[j] + y0[i]) / 2);
          a.push_back((y3[l] - 3 * y2[k] + 3 * y1[j] - y0[i]) / 6);

          coeffs.push_back(a[0] - x[0] * a[1] + x[0] * x[1] * a[2] -
                           x[0] * x[1] * x[2] * a[3]);
          coeffs.push_back(a[1] - (x[0] + x[1]) * a[2] +
                           (x[0] * x[1] + x[0] * x[2] + x[1] * x[2]) * a[3]);
          coeffs.push_back(a[2] - (x[0] + x[1] + x[2]) * a[3]);
          coeffs.push_back(a[3]);

          if ((y3[l] - 3 * y2[k] + 3 * y1[j] - y0[i]) % 6 == 0 &&
              (y3[l] - 3 * y2[k] + 3 * y1[j] - y0[i]) <= polynom[7] * 6 &&
              ((y3[l] - 3 * y2[k] + 3 * y1[j] - y0[i]) != 0 &&
               (polynom[7] * 6) % (y3[l] - 3 * y2[k] + 3 * y1[j] - y0[i]) == 0)) {
            d++;
            bool isZaebis = true;
            for (int i = 0; i < 4; ++i) {
              if (coeffs[i] != wPolynom[i]) {
                isZaebis = false;
              }
            }
            if (isZaebis) {
              printf("\x1b[32m%d) y0: %d; y1: %d; y2: %d; y3: %d\x1b[0m\n", d,
                     y0[i], y1[j], y2[k], y3[l]);
            } else {
              printf("%d) y0: %d; y1: %d; y2: %d; y3: %d\n", d, y0[i], y1[j],
                     y2[k], y3[l]);
            }
          }
        }
      }
    }
  }
}
