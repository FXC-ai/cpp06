# CPP06

[Les conversions de types en C++ • Tutoriels • Zeste de Savoir](https://zestedesavoir.com/tutoriels/553/les-conversions-de-types-en-c/)

[Casting Operators in C++ - GeeksforGeeks](https://www.geeksforgeeks.org/casting-operators-in-cpp/)

# A propos des classes statiques

[Utilisez les éléments statiques et l'amitié](https://openclassrooms.com/fr/courses/7137751-programmez-en-oriente-objet-avec-c/7531961-utilisez-les-elements-statiques-et-lamitie)

Exemple :

```cpp
class MaClassStatic
{
	public:
		MaClassStatic();
		static void maMethodStatic();
};

MaClassStatic::MaClassStatic(){};

void MaClassStatic::maMethodStatic()
{
	std::cout << "Ce module va être difficile." << std::endl;
}
```

# La conversion de type en C

Le cast explicit en C: 

```c
int value = 42;
double value_d = (double) value
```

Le cast implicit en C:

```c
int value = 42;
double value_d = value
```

Dans les 2 cas cela fonctionne de la même manière. Le cas ou il faut faire attention est lorsque l’on passe d’un type plus précis à un type moins précis. Cela entraîne une perte de précision.

Le cast vers un type moins précis :

```c
double value = 42,42f;
int value_i = value;
```

Le flag `-Wconversion` permet d’interdire les cast implicits d’un type plus précis vers un type moins précis.

# La réinterprétation de type en C ou convertion identitaire

En mémoire le codage des bits d’un int et d’un float sont différents. Une réinterprétation permet d’ignorer complétement cela et d’utiliser les bits du float sans modification de codage vers un int. Par conséquent la valeur stockée dans l’int aura une valeur conplêtement différente de la valeur stockée dans le float.

 

```cpp
float c = 42.42f;

std::cout << c << std::endl;

float *ptr_c = &c;

std::cout << ptr_c << std::endl;

long long int *ptr_c_int = (long long int *) ptr_c;

std::cout << ptr_c_int << std::endl;

std::cout << *ptr_c_int << std::endl;
```

output :

```bash
42.42
0x7ff7b1bbc990
0x7ff7b1bbc990
181498654228
```

La valeur de *ptr_c_int est complétement différente de la variable c à cause du casting par réinterprétation. On parle de conversion identitaire. 

Pour ce qui est de la hiérarchie, c’est le type void* qui est au dessus des autres pointeurs.

# Type réinterprétation

Dans la hiérarchie des types, le type const est “en dessus” du type normal. Ainsi, le code suivant ne compile pas :

```cpp
int f = 42;

const int g;

g = f;

std::cout << f << std::endl;
```

Mais ce code là compile :

```cpp
const int f = 42;

int g;

g = f;

std::cout << g << std::endl;
```

La réinterprétation ne peut se faire qu’avec des pointeurs… Const est supérieur au type normal pour les pointeurs et l’inverse pour les int ???

```cpp
int	f = 42;

int const *g = &f;
int const *h = &f;

std::cout << *g << *h << std::endl;

int const *i = &f;
//int *j = i; //NE COMPILE PAS
int *k = (int *) i;
std::cout << *k << std::endl;
```

# Upcast Downcast

## Cast en C

Le code suivant compile, il s’agit d’un downcast

```cpp
class Parent {};
class Child1: public Parent{};
class Child2: public Parent{};

int main()
{

	Child1	a;

	Parent * b = &a;
	Parent * c = (Parent *) &a;

	return 0;
}
```

Le code suivant ne compile pas, il s’agit d’un upcast implicit :

```cpp
class Parent {};
class Child1: public Parent{};
class Child2: public Parent{};

int main()
{
	Child1	a;

	Parent * d = &a;
	Child1 * e = d;

	return 0;
}
```

Le code suivant compile, il s’agit d’un upcast explicit :

```cpp
class Parent {};
class Child1: public Parent{};
class Child2: public Parent{};

int main()
{
	Child1	a;

	Parent * d = &a;
	Child1 * e = (Child1 *) d;

	return 0;
}
```

Malheureusement, ce code ci compile également :

```cpp
class Parent {};
class Child1: public Parent{};
class Child2: public Parent{};

int main()
{
	Child1	a;

	Parent * d = &a;
	Child2 * e = (Child2 *) d;

	return 0;
}
```

## cast en C++

### static_cast

```cpp
/*UPCAST*/
int a = 42;
double b = a;
double c = static_cast<int> (a);
std::cout << b <<std::endl;
std::cout << c <<std::endl;

/*DOWNCAST*/
double d = 42.0f;
int f = static_cast<int> (d);
std::cout << f <<std::endl;
int g = d;                  //FAUX
std::cout << g <<std::endl; 
```

Les upcast peuvent se faire de façon implicit ou non. Les downcast doivent toujours se faire de façon explicit.

```cpp
class Parent {};
class Child1: public Parent{};
class Child2: public Parent{};

int main()
{
	Child1 *h = new Child1;

	Unrelated * i = static_cast<Unrelated *>(h) //IMPOSIBLE
	return 0
}
```

Les cast d’un objet vers un autre qui ne font pas parti du même arbre d’héritage sont interdits.

### dynamic_cast

Ce type de cast ne peut s’effectuer que sur une arborescence dont le parent est une classe abstraite. Le dynamic cast présente l’avantage de détecter les erreurs de cast contrairement au static cast.

```cpp
class Parent {public: virtual ~Parent(){};};
class Child1: public Parent{};
class Child2: public Parent{};

class Unrelated {};

int main()
{
	Child1 a;
	Parent *b = &a;

	Child1 *c = dynamic_cast<Child1 *>(b);
	if (c == NULL)
	{
		std::cout << "NOT OK" << std::endl;
	}
	else
	{
		std::cout << "OK" << std::endl;
	}

	try
	{
		Child2 & d = dynamic_cast<Child2 &>(*b);
		std::cout << "Conversion works" << std::endl;
	}
	catch (std::bad_cast &bc)
	{
		std::cout << bc.what() << std::endl;
	}

	Child2 *e = dynamic_cast<Child2 *>(b);
	if (e == NULL)
	{
		std::cout << "NOT OK" << std::endl;
	}
	else
	{
		std::cout << "OK" << std::endl;
	}
	return 0;
}
```

Dans le premier cas tous fonctionne, mais dans le seconde et dernier cas le cast est impossible car le pointeur parent pointe sur un Child1 et on essaie de caster sur un pointeur de type Child2.

Output :

```cpp
OK
std::bad_cast
NOT OK
```

### reinterpret_cast

Ce code fonctionne parfaitement 

```cpp
char a = 'a';

std::cout << a << std::endl;

int *b = reinterpret_cast<int*>(&a);

std::cout << *b << std::endl;
```

Mais celui ne fonctionne pas ….

```cpp
char a = 'a';

std::cout << a << std::endl;

int b = reinterpret_cast<int>(a);

std::cout << b << std::endl;
```

Voilà la réponse de chat GPT :

Le casting en C++ est strict et doit être utilisé avec prudence. Les deux exemples que vous avez donnés démontrent différentes façons d'utiliser `reinterpret_cast`.

1. Dans le premier exemple:

```cpp
char a = 'a';
std::cout << a << std::endl;
int *b = reinterpret_cast<int*>(&a);
std::cout << *b << std::endl;
```

Vous utilisez `reinterpret_cast` pour changer le type du pointeur. Vous dites essentiellement au compilateur: "Je sais que `&a` est un pointeur vers `char`, mais je veux le traiter comme s'il s'agissait d'un pointeur vers `int`." Notez que cela peut être dangereux, car vous lisez plus de mémoire que celle occupée par un `char` lorsque vous déréférencez `b` (sauf si le `char` est déjà un `int` sur votre plateforme, ce qui est rare).

1. Dans le deuxième exemple:

```cpp
char a = 'a';
std::cout << a << std::endl;
int b = reinterpret_cast<int>(a);
std::cout << b << std::endl;
```

Vous essayez de convertir directement un `char` en `int` en utilisant `reinterpret_cast`. Cela ne fonctionnera pas car `reinterpret_cast` ne fonctionne pas de cette manière. Pour convertir directement des types scalaires comme `char` en `int`, vous n'avez pas besoin de casting explicite, car il y a une conversion implicite disponible. Si vous voulez vraiment un casting explicite, vous devriez utiliser `static_cast` :

```cpp
int b = static_cast<int>(a);
```

En conclusion, `reinterpret_cast` est principalement utilisé pour les conversions de pointeur ou de référence d'un type à un autre, et non pour les conversions directes de types scalaires.

### const_cast

Ce code fonctionne :

```cpp
int a = 42;

int const * b = &a;

int *c = const_cast<int *>(b);
```

Mais pas celui ci :

```cpp
int a = 42;

int const * b = &a;
int *c = b;
```

Pour la raison habituelle, le 2ème exemple ne compile pas car il est impossible de faire des downcast implicits. D’ailleurs il n’est pas recommandé d’utiliser de downcast dans un code. C’est le symptôme d’un problème de structuration.

> Il est également important de savoir qu'un pointeur (ou une référence) constant(e) n'est pas un pointeur ou une référence dont on ne peut modifier la valeur mais dont l'élément pointé ne peut être modifié en passant par ce pointeur (ou cette référence). Cela peut porter à confusion, mais c'est très simple au fond, retenez juste que le mot-clé `const` n'a pas la même signification utilisé pour un objet qu'utilisé pour un pointeur ou une référence.
> 

# opérateurs de classe

Notion simple, c’est une surcharge d’opérateur 

```cpp
#include <iostream>

class testCast 
{

	public :
		testCast(const float v) : _v(v)
		{
		} 

		float getV(){return this->_v;}

		operator float() {return this->_v;}
		operator int() {return static_cast<int>(this->_v);}

	private :
		const float _v;
};

int main()
{
	testCast testCast1(420.234001f);

	int a = testCast1;
	float b = testCast1;

	std::cout << a << std::endl;
	std::cout << b << std::endl;

	return 0;
}
```

# explicit

```cpp
class A{};
class B{};

class C
{
	public :
		C(A const &_){}
		explicit C(B const &_){}
};

void f(C const &_)
{
	std::cout << "OK" << std::endl;
	return;
}

int main()
{
	f( A() );
	f( B() );

	return 0;
}
```

Par le miracle du C++ lorsque l’on envoie un objet A à la place d’un objet C à la fonction f ⇒ cela fonctionne ! Tous se passe comme si on faisait une conversion de type. Comme il y a un constructeur défini dans la classe C qui prend un paramètre A, cela fonctionne un peu à la manière d’un cast.

# Difference entre double et float

| float | double |
| --- | --- |
| Its size is 4 bytes | Its size is 8 bytes |
| It has 7 decimal digits precision | It has 15 decimal digits precision |
| It is an integer [data type](https://www.geeksforgeeks.org/data-types-in-c/) but with decimals | It is an integer data type but with decimals |
| It may get Precision errors while dealing with large numbers | It will not get precision errors while dealing with large numbers. |
| This data type supports up to 7 digits of storage. | This data type supports up to 15 digits of storage. |
| For float data type, the format specifier is %f. | For double data type, the format specifier is %lf. |
| For example -: 3.1415 | For example -: 5.3645803 |
| It is less costly in terms of memory usage. | It is costly in terms of memory usage. |
| It requires less memory space as compared to double data type. | It needs more resources such as occupying more memory space in comparison to float data type. |
| It is suitable in graphics libraries for greater processing power because of its small range. | It is suitable to use in the programming language to prevent errors while 
rounding off the decimal values because of its wide range. |

# Fonction strrol

Fonction de bibliothèque standard C qui analyse une chaîne C-string comme un nombre entier dans la base spécifiée et renvoie une valeur zéro si la conversion n'est pas possible. Il peut être utilisé pour analyser un `std::string` et déterminez si la string est numérique, comme indiqué ci-dessous.

```cpp
#include <iostream>
#include <string>
 
bool isNumeric(std::string const &str)
{
    char* p;
    strtol(str.c_str(), &p, 10);
    return *p == 0;
}
 
int main()
{
    std::string str = "100";
 
    std::cout << std::boolalpha << isNumeric(str) << std::endl;        // true
 
    return 0;
}
```

# Conversion std::string en double

[C++ Program For String to Double Conversion - GeeksforGeeks](https://www.geeksforgeeks.org/cpp-program-for-string-to-double-conversion/)

