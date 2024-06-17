#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*ДОБРО ПОЖАЛОВАТЬ, ЗДЕСЬ ПРЕДСТАВЛЕНЫ ВСЕ АЛГОРИТМЫ ИЗ ПРАКТИЧЕСКОГО ЗАДАНИЯ 1.1 | СИАОД*/
/*ВНИМАНИЕ, ВСЕ ПРОВЕРКИ НА ВВОД ДЕЛАТЬ В main() САМИМ. ЕСЛИ ЕСТЬ ВОПРОСЫ, ТО ПИШИТЕ tg: @pawtf*/

/*Первый алгоритм*/
void delFirstMetod(int* x, int n, int key) {
    int i = 1;
    while (i <= n) {
        if (x[i] == key) {
            for (int j = i; j < n - 1; ++j) {
                x[j] = x[j + 1];
            }
            n--;
        }
        else {
            i++;
        }
    }
    /*ВЫВОД*/
    for (int i = 0; i < n; ++i) {
        cout << x[i] << " ";
    }
}

/*Второй алгоритм*/
void delOtherMetod(int* x, int n, int key) {
    int j = 1;
    for (int i = 1; i < n; ++i) {
        x[j] = x[i];
        if (x[i] != key) {
            j++;
        }
    }
    n = j;
    /*ВЫВОД*/
    for (int i = 0; i < n; ++i) {
        cout << x[i] << " ";
    }
}

/*1.1WorK*/
void N1() {
    srand(time(NULL));
    cout << "1WOrk.\n1 -> ";
    int M[10] = {}, M1[10] = {}, M2[10] = {}, key = 0;
    for (size_t i = 0; i < 10; ++i) {
        M[i] = rand() % 10;
        M1[i] = M[i];
        M2[i] = M[i];
        cout << M[i] << " ";
    }
    cout << "ВВЕДИТЕ КЛЮЧ -> ";
    cin >> key;
    cout << "Ready.....";
    cout << "\n2.1 -> ";
    delFirstMetod(M1, 10, key);
    cout << "\n2.2 -> ";
    delOtherMetod(M2, 10, key);
}


/*1.2VARIANTS*/
void VAR_1(int** x1, int** x2, int** result, int rows, int colums) {
    /*Умножение квадратных матриц.*/
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < colums; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < rows; k++) {
                result[i][j] += x1[i][k] * x2[k][j];
            }
        }
    }
}

void VAR_2(int** x, int** vect, int N, int M, int N_V, int M_V) {
    /*Умножение матрицы на вектор.*/
    vector <int> Vect1 = {};
    for (int i = 0; i < N_V; ++i) {
        for (int j = 0; j < M_V; ++j) {
            Vect1.push_back(vect[i][j]);
        }
    }
    /*ВЕКТОР-СТОЛБЕЦ*/
    if (N_V != 1) {
        for (int i = 0; i < N; ++i) {
            int sum = 0;
            for (int j = 0; j < M; ++j) {
                sum += x[i][j] * Vect1[j];
            }
            cout << sum << "\n";
        }
    }
    /*ВЕКТОР-СТРОКА*/
    else {
        vector <int> A = {};
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                A.push_back(x[i][j]);
            }
        }
        for (int i = 0; i < A.size(); ++i) {
            for (int j = 0; j < Vect1.size(); ++j) {  
                cout << A[i] * Vect1[j] << " ";
            }
            cout << "\n";
        }
    }
}

void VAR_3(int** x, int** y, int N, int M) {
    /*Сложение двух матриц.*/
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cout << x[i][j] + y[i][j] << " ";
        }
        cout << "\n";
    }
}

/*.!.*/
void VAR_4(int** x, int N, int M) {
    /*Получение матрицы обратной данной матрице.*/
    /*Не придумал, -_-*/
    /*Здесь поможет возможно решение рекурсией из интернета, НО ЭТО НЕ ПОЛНЦЕННЫЙ АЛГОРИТМ В ВИДЕ 1 ФУНКЦИИ!*/
}

void VAR_5(int** matrix, int N, int M) {
    /*Обход матрицы по спирали (по часовой стрелке: первая строка, по-
следний столбец, нижняя строка, первый столбец)*/
    int top = 0, bottom = N - 1;
    int left = 0, right = M - 1;
    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++) {
            cout << matrix[top][i] << " ";
        }
        top++;
        for (int i = top; i <= bottom; i++) {
            cout << matrix[i][right] << " ";
        }
        right--;
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                cout << matrix[bottom][i] << " ";
            }
            bottom--;
        }
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                cout << matrix[i][left] << " ";
            }
            left++;
        }
    }
}

void VAR_6(int** x, int N, int M) {
    /*Найти максимальный элемент в части матрицы, расположенной над
главной диагональю.*/
    int max = 0; 
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (i != j and j > i) {
                if (x[i][j] > max) {
                    max = x[i][j];
                }
            }
        }
    }
    /*ВЫВОД
    cout << "МАКСИМАЛЬНЫЙ ЭЛЕМЕНТ -> " << max;*/
}

void VAR_7(int** x, int N, int M) {
    /*Найти минимальное четное число в части матрицы – между главной и
побочной диагоналями (диагонали образуют вертикальные песочные
часы).*/
    int one = N - 1, two = 0;;
    vector <string> diag = { to_string(N - 1) + "0" };
    vector <int> new_numb;
    string start = to_string(N - 1) + "0";
    while (start != ("0" + to_string(N - 1))) {
        one--;
        two++;
        start = to_string(one) + to_string(two);
        diag.push_back(start);
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (i != j) {
                for (int k = 0; k < diag.size(); ++k) {
                    if (diag[k] != (to_string(i) + to_string(j))) {
                        if (x[i][j] % 2 == 0) {
                            if (find(new_numb.begin(), new_numb.end(), x[i][j]) == new_numb.end()) {
                                new_numb.push_back(x[i][j]);
                            }
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < new_numb.size(); i++) {
        for (int j = 0; j < new_numb.size() - 1; j++) {
            if (new_numb[j] > new_numb[j + 1]) {
                int temp = new_numb[j];
                new_numb[j] = new_numb[j + 1];
                new_numb[j + 1] = temp;
            }
        }
    }
    /*ВЫВОД
    cout << "ЧИСЛО -> " << new_numb[0] << "\n";*/
}

void VAR_8(int** x, int N, int M) {
    /*Найти восходящую диагональ матрицы с максимальной суммой эле-
ментов.*/
    /*Для любой восходящей диагонали сумма номера строки и номера столбца постоянна и 
    для разных диагоналей - разная, то есть i + j = const1.*/
    int maxSum = 0, maxRow = 0;
    for (int i = 0; i < N; ++i) {
        int currentSum = 0;
        for (int j = 0; j < N && i + j < N; ++j) {
            currentSum += x[i + j][j];
        }
        if (currentSum > maxSum) {
            maxSum = currentSum;
            maxRow = i;
        }
    }
    /*ВЫВОД
    cout << "ВОСХОДЯЩАЯ ДИАГОНАЛЬ НАХОДИТСЯ В СТРОКЕ -> " << maxRow;*/
}

void VAR_9(int** x, int N, int M) {
    /*Определить, симметрична ли матрица относительно главной диаго-
нали.*/
    bool flag = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (i != j) {
                if (x[i][j] != x[j][i]) {
                    flag = 1;
                }
            }
        }
    }
    /*ВЫВОД
    if (flag == 1) {
        cout << "МАТРИЦА НЕСИММЕТРИЧНА.";
    }
    else {
        cout << "МАТРИЦА СИММЕТРИЧНА.";
    }*/
}

void VAR_10(int** x, int N, int M) {
    /*Выполнить транспонирование матрицы.*/
    int** x1 = new int* [N];
    for (int i = 0; i < N; ++i) {
        x1[i] = new int[M];
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            x1[i][j] = x[j][i];
        }
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            x[i][j] = x1[i][j];
        }
    }
    for (int i = 0; i < N; ++i) {
        delete[] x1[i];
    }
    delete[] x1;
}

void VAR_11(int* x, int n) {
    /*Дан одномерный массив из n элементов целого типа. Определить,
сколько раз в массив входит максимальное значение.*/
    int cnt = 0, max = 0;
    for (int i = 0; i < n; ++i) {
        if (x[i] > max) {
            max = x[i];
        }
    }
    for (int i = 0; i < n; ++i) {
        if (x[i] == max) {
            cnt++;
        }
    }
    /*ВЫВОД
    cout << "\nЧИСЛО -> " << max << ". КОЛИЧЕСТВО -> " << cnt;*/
}

void VAR_12(int* x, int n, int y) {
    /*Схема Горнера*/
    int result = x[0];
    for (int i = 1; i <= n; i++) {
        result = result * y + x[i];
    }
    /*ВЫВОД
    cout << "ЗНАЧЕНИЕ МНОГОЧЛЕНА В ТОЧКЕ Y -> " << result;*/
}

void VAR_13(int** x, int N, int M) {
    /*Дана прямоугольная матрица размером n*m. Определить максималь-
ное из чисел, встретившихся в матрице более одного раза*/
    vector <int> NUMB = {}, cnt_num = {};
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (find(NUMB.begin(), NUMB.end(), x[i][j]) == NUMB.end()) {
                NUMB.push_back(x[i][j]);
                cnt_num.push_back(0);
            }         
        }
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            for (int k = 0; k < NUMB.size(); ++k) {
                if (NUMB[k] == x[i][j]) {
                    cnt_num[k]++;
                }
            }
        }
    }
    int max = 0;
    for (int i = 0; i < cnt_num.size(); ++i) {
        if (cnt_num[i] > 1 and NUMB[i] > max) {
            max = NUMB[i];
        }
    }
    /*ВЫВОД
    cout << "МАКСИМАЛЬНОЕ ЧИСЛО -> " << max;*/
}

void VAR_14(vector<vector<double>>& matrix) {
    int n = matrix.size(); // Количество уравнений
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double coeff = -matrix[j][i] / matrix[i][i];
            for (int k = i; k < n + 1; k++) {
                matrix[j][k] += coeff * matrix[i][k];
            }
        }
    }
}

void VAR_15(int** x, int N, int M) {
    /*Характеристикой строки матрицы назовем сумму ее положительных четных
элементов. Переставляя строки заданной матрицы, расположить их в
соответствии с ростом характеристик.*/
    vector <int> SUMZ = {}, minz = {};
    for (int i = 0; i < N; ++i) {
        int sum = 0;
        for (int j = 0; j < M; ++j) {
            if (x[i][j] % 2 == 0) {
                sum += x[i][j];
            }
        }
        SUMZ.push_back(sum);
        minz.push_back(i);
    }
    for (int i = 0; i < SUMZ.size(); i++) {
        for (int j = 0; j < SUMZ.size() - 1; j++) {
            if (SUMZ[j] > SUMZ[j + 1]) {
                int a = SUMZ[j], b = minz[j];
                SUMZ[j] = SUMZ[j + 1];
                SUMZ[j + 1] = a;
                minz[j] = minz[j + 1];
                minz[j + 1] = b;
            }
        }
    }
    /*ВЫВОД
    for (int i = 0; i < SUMZ.size(); ++i) {
        for (int j = 0; j < M; ++j) {
            cout << x[minz[i]][j] << " ";
        }
        cout << "\n";
    }*/
}

void VAR_16(int** x, int N, int M) {
    /*Дана целочисленная квадратная матрица размером n*n. Найти мини-
мум среди сумм модулей элементов диагоналей параллельных побоч-
ной диагонали.*/
    vector <int> sum = {};
    /*ДО ПОБОЧНОЙ*/
    for (int j = 1; j < M - 1; ++j) {
        int sum_of_elem = x[j][0], index1 = 0, index2 = j;
        string start = (to_string(index1) + to_string(index2)), end = (to_string(index2) + to_string(index1));
        while (start != end) {
            sum_of_elem += abs(x[index1][index2]);
            index1++;
            index2--;
            start = (to_string(index1) + to_string(index2));
        }
        sum.push_back(sum_of_elem);
    }
    /*ПОСЛЕ ПОБОЧНОЙ*/
    for (int j = 1; j < M - 1; ++j) {
        int sum_of_elem = x[j][M - 1], index1 = M - 1, index2 = j;
        string start = (to_string(index1) + to_string(index2)), end = (to_string(index2) + to_string(index1));
        while (start != end) {
            sum_of_elem += abs(x[index1][index2]);
            index1--;
            index2++;
            start = (to_string(index1) + to_string(index2));
        }
        sum.push_back(sum_of_elem);
    }
    int cnt = sum[0];
    for (int i = 0; i < sum.size(); ++i) {
        if (cnt > sum[i]) {
            cnt = sum[i];
        }
    }
    /*ВЫВОД
    cout << "МИНИМАЛЬНАЯ СУММА -> " << cnt;*/
}

void VAR_17(int** x, int N, int M) {
    /*Дана целочисленная прямоугольная матрица размером n*m. Опреде-
лить номер строки, в которой находится самая длинная серия одина-
ковых элементов.*/
    vector <int> row = {};
    for (int i = 0; i < N; ++i) {
        row.push_back(0);
    }
    for (int i = 0; i < N; ++i) {
        int the_most_longest = 0;
        for (int j = 0; j < M; ++j) {
            int flag = x[i][j], cnt = 1, index_next_elem = j + 1;
            while (flag == x[i][index_next_elem]) {
                cnt++;
                index_next_elem++;
            }
            if (cnt > the_most_longest) {
                the_most_longest = cnt;
            }
        }
        row[i] = the_most_longest;
    }
    int max = 0;
    for (int i = 0; i < N; ++i) {
        if (row[i] > max) {
            max = row[i];
        }
    }
    /*ВЫВОД
    cout << "МАКСИМАЛЬНЫЕ СЕРИИ ->\n";
    for (int i = 0; i < N; ++i) {
        if (max == row[i]) {
            cout << "СТРОКА #" << i << ". СЕРИЯ -> " << row[i] << "\n";
        }
    }*/
}

void VAR_18(int* x, int n) {
    /*Дан массив из n элементов целого типа. Преобразовать массив следу-
ющим образом, чтобы сначала располагались все элементы равные 0,
затем все остальные.*/
    vector <int> M;
    for (size_t i = 0; i < n; ++i) {
        if (x[i] == 0) {
            M.push_back(0);
        }
    }
    for (size_t i = 0; i < n; ++i) {
        if (x[i] != 0) {
            M.push_back(x[i]);
        }
    }
    for (int i = 0; i < M.size(); ++i) {
        x[i] = M[i];
    }
}

void VAR_19(int n) {
    /*Найти количество натуральных чисел, не превосходящих заданного n
и делящихся на каждую из своих цифр.*/
    int cnt = 0;
    for (int i = 1; i < n; ++i) {
        bool flag = 0;
        for (int j = 0; j < to_string(i).length(); ++j) {
            int numb = (to_string(i))[j] - '0';
            if (numb == 0) {
                flag = 1;
            }
            else {
                if (i % numb == 0) {
                    flag = 0;
                }
                else {
                    flag = 1;
                    break;
                }
            }
        }
        if (flag == 0) {
            cnt++;
        }
    }
    /*ВЫВОД
    cout << "КОЛИЧЕСТВО -> " << cnt;*/
}


int main(void)
{
    /*ПРИЯТНОГО ПОЛЬЗОВАНИЯ*/
}
