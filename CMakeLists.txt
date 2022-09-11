cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 14)

# set the project name
project(NumberConverter)

# create executable
aux_source_directory(./src DIR_SRCS)
add_executable(NumberConverter main.cpp ${DIR_SRCS})

# set include directories
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include")

enable_testing()

function(do_test target num arg result)
    add_test(NAME Test${num} COMMAND ${target} ${arg})
    set_tests_properties(Test${num}
        PROPERTIES PASS_REGULAR_EXPRESSION ${result})
endfunction()

do_test(NumberConverter 1 "one hundred and one" "101")
do_test(NumberConverter 2 "I have one hundred apples" "I have 100 apples")
do_test(NumberConverter 3 "This is test number four thousand, five hundred and two" "This is test number 4502")
do_test(NumberConverter 4 "I have a million, five hundred thousand, twenty five dogs and two hundred and ninety-nine cats" "I have a 1500025 dogs and 299 cats")
do_test(NumberConverter 5 "twenty-five thousand, seven hundred and ten minutes have passed" "25710 minutes have passed")
do_test(NumberConverter 6 "one billion, twenty million, three hundred and two thousand and sixty-six" "A number is bigger than the limit of 10\\^9")
do_test(NumberConverter 7 "ninety million and seven" "90000007")
do_test(NumberConverter 8 "I have two cars, one house and nineteen hundred bucks in the bank" "I have 2 cars, 1 house and 1900 bucks in the bank")
do_test(NumberConverter 9 "fifteen million, one hundred and sixty-one thousand, five hundred and sixteen" "15161516")
do_test(NumberConverter 10 "nine hundred and ninety-nine million, nine hundred and ninety-nine thousand, nine hundred and ninety-nine " "999999999")
do_test(NumberConverter 11 "one billion" "1000000000")
do_test(NumberConverter 12 "one billion and one" "A number is bigger than the limit of 10\\^9")
