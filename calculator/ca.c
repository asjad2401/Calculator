#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int logi();
int arith();
int trigo();
int perc();
int natlog();
int comlog();
int logrithm();

int main()
{
    char x;
    printf("Choose from the following options: \n A. Arithmetic\n B. Trignometric\n C. Log\n D. Percentage\n");
    (scanf(" %c", &x));

    switch (x)
    {
    case 'A': arith(); break;
    case 'B': trigo(); break;
    case 'C': logi(); break;
    case 'D': perc(); break;

    default: printf("You entered an Invalid option"); break;
    }
    return 0;
}

int arith()
{
    float a, b;
    char op;
    char func[20];
    printf("Write your desired operation of the form \"a+b\"\n");
    scanf("%19s", func); // take input in the array func

    int i = 0;
    while (func[i] != '\0') { // loop iterates through array till null terminator is reached
        if (func[i] == '+' || func[i] == '-' || func[i] == '*' || func[i] == '/')
        { // if at any point in array an operation is found, loop breaks
            break;
        }i++;
    }

    if (i == 0 || func[i] == '\0' || func[i + 1] == '\0') // prints error if no operator is found
    {
        printf("No operator found");
        return 1;
    };

    if (sscanf(func, "%f%c%f", &a, &op, &b) != 3)
    {
        printf("Invalid number format in input.\n");
        return 1;
    }

    float result;

    switch (op)
    {

    case '+': result = a + b; break;
    case '-': result = a - b; break;
    case '*': result = a * b; break;
    case '/':
        if (b == 0){
             printf("division by 0 not possible!\n");
            return 1;
        }else{
            result = a / b;
        }break;

    default:
        printf("invalid operation");
        return 1;
    }
    printf("%.2f %c %.2f = %.2f", a, op, b, result);
    return 0;
}

int trigo()

{
    char fu[10]; // declare an array which will take input
    char c[4];  // declare an array which will take value to function ie tan sin cos etc
    float d;
    double p = 3.14159265;

    printf("Enter trignometric function of the format \"tan45\"\n");
    scanf("%6s", fu); // take input in form of tan45 and store in array fu

    sscanf(fu, "%3s%f", &c, &d); //takes first 3 characters from array and put it in c and put remaining in d 
 
    d = d * p / 180;
    double result;

    if (strcmp(c, "sin") == 0) // check if c is sin
    {
        result = sin(d);
    }

    else if (strcmp(c, "cos") == 0)
    {
        result = cos(d);
    }

    else if (strcmp(c, "tan") == 0) // check if c is tan
    {
        if (fabs(cos(d) - 0) < 1e-6)
        {
            printf("Undefined");
            return 1;
        } // if angle is 90 degrees, print undefined and return 1.
        else
            result = tan(d);
    }

    else if (strcmp(c, "sec") == 0)
    {
        if (fabs(cos(d) - 0) < 1e-6)
        {
            printf("Udefined");
            return 1;
        }
        else
            result = 1 / cos(d);
    }

    else if (strcmp(c, "csc") == 0)
    {
        if (fabs(sin(d) - 0) < 1e-6)
        {
            printf("Undefined");
            return 1;
        }
        else
            result = 1 / sin(d);
    }

    else if (strcmp(c, "cot") == 0)
    {
        if (fabs(sin(d) - 0) < 1e-6)
        {
            printf("Undefined");
            return 1;
        }
        else
            result = 1 / tan(d);
    }

    else
    {
        printf("invalid"); return 1;
    }

    printf("%.4lf", result); // print the answer
}

int logi()
{
    char l;
    printf("Choose from the following:\nA. Natural log\nB. Common log\nC. Any base\n");
    scanf(" %c", &l);
    if (l == 'A')
    {
        natlog();
    }
    else if (l == 'B')
    {
        comlog();
    }
    else if (l == 'C')
    {
        logrithm();
    }

    return 0;
}

int natlog()
{
    double n;
    printf("ln ");
    scanf("%lf", &n);
    if (n <= 0)
    {
        printf("undefined");
    }
    else
    {
        printf("natural log of %lf is %lf", n, log(n));
    }
    return 0;
}

int comlog()
{
    double m;
    printf("log ");
    scanf("%lf", &m);
    if (m <= 0)
    {
        printf("undefined");
    }
    else
    {
        printf("natural log of %lf is %lf", m, log10(m));
    }

    return 0;
}

int logrithm()
{
    double f;
    double g;

    printf("First enter the number and then enter the base \nlog ");
    scanf("%lf", &f);

    printf("base ");
    scanf("%lf", &g);

    if (f <= 0, g <= 0)
    {
        printf("undefined");
    }
    else
    {
        printf("log %lf base %lf is %lf", f, g, log10(f) / log10(g));
    }

    return 0;
}

int perc()
{
    int s, t;
    printf("Enter Obtained marks ");
    scanf("%i", &s);

    printf("Enter Total marks ");
    scanf("%i", &t);
    int y = 100 * s / t;

    printf("The percentage is %d", y);

    return 0;
}
