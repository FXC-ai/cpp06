echo "__________EXEMPLES CORRECTION_________"
./convert 0
./convert nan
./convert 42.0f

echo "__________TESTS CHAR__________\n";
./convert a
./convert B
./convert "*"

echo "__________TESTS INT__________\n";

./convert 42
./convert 9999999
./convert 2147483647
./convert -2147483648

echo "__________TESTS FLOAT__________\n";

echo "__________TESTS DOUBLE__________\n";
./convert 42.0



echo "__________TESTS NAN__________\n";