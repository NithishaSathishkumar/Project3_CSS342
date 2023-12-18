// #include <iostream>
// #include <sstream>

// #include "list342.h"

// using namespace std;

// bool InsertTest() {

//     List342<int> list;
//     bool ret = true;
//     stringstream results;

//     int test_array[15] = {0, 4, 1, 9, 8, 3, 3, 1, 6, -5, 10, 5, 8, 4};
//     int size = 15;
//     int* data_ptr = &test_array[0];

//     for (int i = 0; i < size; i++) {

//         list.Insert(data_ptr);
//         ++data_ptr;
//     }

//     // cout << "LIST:" << endl;
//     // cout << list << endl;

//     results << list;

//     if (results.str() != "-50134568910") {

//         ret = false;
//     }

//     return ret; 
// }

// bool RemoveTest() {

//     List342<int> list;
//     int result = 0;
//     bool ret = false;
//     stringstream results;

//     if (! (list.Remove(5, result)) && result == 0) {

//         ret = true;
//     }

//     // cout << "LIST:" << endl;
//     // cout << list << endl;

//     if (ret) {
        
//         int test_array1[15] = {0, 4, 1, 9, 8, 3, 3, 1, 6, -5, 10, 5, 8, 4};
//         int size1 = 15;
//         int* data_ptr = &test_array1[0];

//         for (int i = 0; i < size1; i++) {

//             list.Insert(data_ptr);
//             ++data_ptr;
//         }

//         int test_array2[7] = {-5, 0, 8, 10, 30, 12, 4};
//         int size2 = 7;

//         for (int j = 0; j < size2; j++) {

//             list.Remove(test_array2[j], result);

//             result = 0;
//         }

//         //cout << "LIST:" << endl;
//         //cout << list << endl;

//         results << list;

//         if (results.str() != "13569") {

//             ret = false;
//         }

//     }

//     return ret;
// }

// bool PeekTest() {

//     List342<int> list;
//     int result = 0;
//     bool ret = false;

//     if ( !(list.Peek(5, result)) && result == 0) {

//         ret = true;
//     }

//     if (ret) {

//         int test_array1[8] = {1, 2, 3, 4, 5, 6, 7, 8};
//         int size1 = 8;
//         int* data_ptr = &test_array1[0];

//         for (int i = 0; i < size1; i++) {

//             list.Insert(data_ptr);
//             ++data_ptr;
//         }

//         int test_array2[6] = {4, 1, 8, 3, 0, 9};
//         int size2 = 6;

//         for (int j = 0; j < 4; j++) {

//             if (list.Peek(test_array2[j], result) && result == test_array2[j]) {

//                 ret = true;
//             } else {

//                 ret = false;
//                 break;
//             }

//             result = 0;
//         }

//         for (int m = 4; m < size2; m++) {

//             if ( !(list.Peek(test_array2[m], result)) && result == 0) {

//                 ret = true;
//             } else {

//                 ret = false;
//                 break;
//             }
//         }
//     }

//     return ret;
// }

// bool SizeTest() {

//     List342<int> list;
//     bool ret = false;

//     if (list.Size() == 0) { //works

//         ret = true;
//     }

//     if (ret) {

//         for (int i = 0; i < 6; i++) {
            
//             list.Insert(&i);
//         }
        
//         if (list.Size() != 6) {

//             ret = false;
//         }
//     }

//     cout << "LIST: " << endl;
//     cout << list << endl;

//     return ret;
// }

// bool EqualityTest() {

//     List342<int> list1(7);
//     bool ret = false;
    
//     if (list1 == list1) {

//         ret = true;
//     }

//     if (ret) {

//         List342<int> list2;
//         List342<int> list3;

//         if (list2 == list3); 
//         else {

//             ret = false;
//         }
//     }

//     if (ret) {

//         List342<int> list4;
//         List342<int> list5;

//         for (int i = 0; i < 5; i++) {

//             list4.Insert(&i);
//         }

//         for (int j = 0; j < 4; j++) {

//             list5.Insert(&j);
//         }

//         if (list4 == list5) {

//             ret = false;
//         }
//     }

//     if (ret) {

//         List342<int> list6;
//         List342<int> list7;

//         for (int i = 0; i < 5; i++) {

//             list6.Insert(&i);
//             list7.Insert(&i);
//         }

//         if (list6 == list7); 
//         else {

//             ret = false;
//         }
//     }

//     if (ret) {

//         List342<int> list8;
//         List342<int> list9;
//         int SIX = 6;

//         for (int i = 0; i < 5; i++) {

//             list8.Insert(&i);
//         }

//         for (int j = 0; j < 4; j++) {

//             list9.Insert(&j);
//         }

//         list9.Insert(&SIX);

//         if (list8 == list9) {

//             ret = false;
//         } 
//     }

//     return ret;
// }

// bool InequalityTest() {

//     List342<int> list1(6);
//     List342<int> list2(1);

//     bool ret = false;

//     if (list1 != list2) {

//         ret = true;
//     } 

//     return ret;
// }

// bool AssignmentTest() {

//     List342<int> list1(7);
//     List342<int> list2;
    
//     list2 = list1;

//     bool ret = false;

//     if (list2 == list1) { //works

//         ret = true;
//     }

//     if (ret) {

//         List342<int> list4;
//         int SEVEN = 7;

//         list4.Insert(&SEVEN);

//         List342<int> list3 = list4;

//         if (list3 != list4) { //works

//             ret = false;
//         }
//     }
    
//     if (ret) {

//         List342<int> list5;
//         int FIVE = 5;
//         list5.Insert(&FIVE);

//         List342<int> list6(list5);

//         if (list5 != list6) { //works

//             ret = false;
//         }
//     }

//     if (ret) {

//         List342<int> list7;
//         int SEVEN = 7;
//         list7.Insert(&SEVEN);
        
//         list7 = list7;
//         stringstream result;

//         result << list7;

//         if (result.str() != "7"){ //works

//             ret = false;
//         }
//     }

//     if (ret) {

//         List342<int> empty_list;
//         List342<int> list8;
//         int EIGHT = 8;
//         list8.Insert(&EIGHT);

//         stringstream result;

//         list8 = empty_list;
//         cout << empty_list;

//         result << list8;
//         cout << list8;

//         if (result.str() != "") {

//             ret = false;
//         }
//     }

//     if (ret) {

//         List342<int> list9;
//         List342<int> list10;
//         stringstream result;

//         for (int i = 0; i < 5; i++) {

//             list9.Insert(&i);
//         }

//         list10 = list9;

//         result << list10;

//         if (result.str() != "01234") {

//             ret = false;
//         }
//     }

//     if (ret) {

//         List342<int> list11;
//         List342<int> list12;

//         stringstream result;

//         for (int i = 0; i < 10; i++) {

//             list11.Insert(&i);
//         }

//         for (int i = 0; i < 20; i++) {

//             list12.Insert(&i);
//         }

//         list12 = list11;

//         result << list12;

//         if (result.str() != "0123456789") {

//             ret = false;
//         }
//     }

//     return ret;
// }

// bool DeleteListTest() {

//     bool ret = false;
//     List342<int> nothing_list;
//     List342<int> list;

//     for (int i = 0; i < 20; i++) {

//         list.Insert(&i);
//     }

//     // cout << "BEFORE DELETION: " << endl;
//     // cout << list << endl; 

//     list.DeleteList();

//     // cout << "AFTER DELETION: " << endl;
//     // cout << list << endl;

//     if (list == nothing_list) {

//         ret = true;
//     }

//     return ret;
// }

// bool AdditionOperatorTest() {

//     List342<int> list1, list2, result;
//     bool ret = false;
//     stringstream result_string;

//     for (int i = 0; i < 20; i++) {

//         if (i % 2 == 0) {

//             list1.Insert(&i);
//         } else if (i % 2 == 1) {

//             list2.Insert(&i);
//         }
//     }
   
//     result = list1 + list2; 
   
//     result_string << result;

//     if (result_string.str() == "012345678910111213141516171819") {

//         ret = true;
//     }

//     return ret;
// }

// bool AdditionAssignmentTest() {

//     List342<int> list1;
//     List342<int> list2(7);
//     bool ret = false;

//     list1 += list2;

//     if (list1 == list2) { //work

//         ret = true;
//     }

//     if (ret) {

//         List342<int> list3;
//         List342<int> list4(7);
//         stringstream result;

//         list4 += list3;

//         result << list4; 

//         if (result.str() != "7") { //works

//             ret = false;
//         }
//     }

//     if (ret) {

//         List342<int> list5(7);
//         stringstream result;

//         result << list5;
        
//         list5 += list5;

//         if (result.str() != "7") { //works

//             ret = false;
//         }
//     }

//     if (ret) {

//         List342<int> list6, list7;
//         stringstream result;

//         for (int i = 0; i < 10; i++) {

//             list6.Insert(&i);
//         }

//         for (int j = 0; j < 20; j++){

//             if (j % 2 == 0) {

//                 list7.Insert(&j);
//             }
//         }

//         list6 += list7;

//         result << list6;

//         if (result.str() != "01234567891012141618") {//works

//             ret = false;
//         }
//     }
//     if (ret) {

//         List342<int> list8, list9;
//         stringstream result;

//         for (int i = 0; i < 10; i++){

//             list8.Insert(&i);
//         }

//         int test_array1[6] = {-5, -2, 4, 9, 12, 14};
//         int size1 = 6;
//         int* data_ptr = &test_array1[0];

//         for (int j = 0; j < size1; j++) {

//             list9.Insert(data_ptr);
//             ++data_ptr;
//         }

//         list8 += list9;

//         result << list8;

//         if (result.str() != "-5-201234567891214") {//works

//             ret = false;
//         }
//     }

//     if (ret) {

//         List342<int> list10, list11;
//         stringstream result;

//         for (int i = 0; i < 10; i++){

//             list10.Insert(&i);
//         }

//         int test_array2[15] = {-7, -3, -1, 1, 3, 4, 6, 9, 12, 14, 10, 5, 19, 35, 1};
//         int size2 = 15;
//         int* data_ptr = &test_array2[0];

//         for (int j = 0; j < size2; j++) {

//             list11.Insert(data_ptr);
//             ++data_ptr;
//         }

//         list10 += list11;

//         result << list10;

//         if (result.str() != "-7-3-101234567891012141935") {//works

//             ret = false;
//         }
//     }

//     return ret;
// }

// bool MergeTest() {

//     bool ret = true;
//     stringstream results;

//     List342<int> list1(7);

//     list1.Merge(list1);

//     results << list1;

//     if (results.str() == "7"){ //works

//         ret = true;
//     }

//     if (ret) {

//         List342<int> list2;
//         stringstream result;

//         list1.Merge(list2);

//         result << list1;

//         if (result.str() != "7") {//works

//             ret = false;
//         }
//     }

//     if (ret) {

//         List342<int> list3;
//         stringstream result1;
//         stringstream result2;

//         list3.Merge(list1);

//         result1 << list3;
//         result2 << list1;

//         if (result1.str() != "7" && result2.str() != "") { //works

//             ret = false;
//         }
//     }

//     if (ret) {

//         List342<int> list4;
//         List342<int> list5;
//         stringstream result1;
//         stringstream result2;

//         for (int i = 0; i < 20; i++) {

//             if (i % 2 == 1) {

//                 list4.Insert(&i);
//             }
//         }

//         for (int j = 0; j < 20; j++) {

//             if (j % 2 == 0) {

//                 list5.Insert(&j);
//             }
//         }

//         list4.Merge(list5);

//         result1 << list4;
//         result2 << list5;

//         if (result1.str() != "012345678910111213141516171819" && result2.str() != "") {//works

//             ret = false;
//         } 
//     }

//     if (ret) {

//         List342<int> list6;
//         List342<int> list7;
//         stringstream result1;
//         stringstream result2;

//         int test_array1[12] = {0, 2, 3, 4, 6, 7, 8, 10, 12, 13, 14, 17};
//         int size1 = 12;

//         for (int i = 0; i < size1; i++) {

//             list6.Insert(&i);
//         }

//         int test_array2[10] = {0, 1, 5, 9, 11, 15, 18, 19, 20, 21};
//         int size2 = 10;

//         for (int j = 0; j < size2; j++){

//             list7.Insert(&j);
//         }

//         list6.Merge(list7);

//         result1 << list6;
//         result2 << list7;

//         if (result1.str() != "012345678991011121314151718192021" && result2.str() != "") {

//             ret = false;
//         }
//     }

//     if (ret) {

//         List342<int> list8;
//         List342<int> list9;
//         stringstream result1;
//         stringstream result2;

//         int test_array1[14] = {0, 1, 2, 3, 6, 7, 8, 10, 12, 13, 14, 17, 25, 30};
//         int size1 = 14;

//         for (int i = 0; i < size1; i++) {

//             list8.Insert(&i);
//         }

//         int test_array2[18] = {-5, 0, 1, 3, 4, 5, 7, 9, 11, 12, 14, 15, 18, 19, 20, 25, 30, 31};
//         int size2 = 18;

//         for (int j = 0; j < size2; j++){

//             list9.Insert(&j);
//         }

//         list8.Merge(list9);

//         result1 << list8;
//         result2 << list9;

//         if (result1.str() != "-5012345678910111213141517181920253031" && result2.str() != "") {

//             ret = false;
//         }
//     }

//     return ret;
// }

// bool BuildListTest(string file_name_correct, string file_name_wrong) {

//     List342<int> list;
//     List342<int> list2;
//     bool ret = false;
//     stringstream result_string;

//     if ( list.BuildList(file_name_correct) && !(list2.BuildList(file_name_wrong))) {

//         ret = true;
//     }

//     result_string << list;
//     cout << list;

//     if (ret && result_string.str() == "012345101730") {

//         ret = true;
//     }

//     return ret;
// }

// int main(int args, char* argv[]) {

//     stringstream file_name1(argv[args - 2]);
//     stringstream file_name2(argv[args - 1]);
    
//     if (BuildListTest(file_name1.str(), file_name2.str())) {

//         cout << "\e[1;32mBUILDLIST TEST           PASSED" << endl;
//     } else {

//         cout << "\e[1;31mBUILDLIST TEST           FAILED" << endl;
//     }

//     if (InsertTest()) {

//         cout << "\e[1;32mINSERT TEST              PASSED" << endl;
//     } else {

//         cout << "\e[1;31mINSERT TEST              FAILED" << endl;
//     }

//     if (RemoveTest()) {

//         cout << "\e[1;32mREMOVE TEST              PASSED" << endl;
//     } else {

//         cout << "\e[1;31mREMOVE TEST              FAILED" << endl;
//     }

//     if (PeekTest()) {

//         cout << "\e[1;32mPEEK TEST                PASSED" << endl;
//     } else {

//         cout << "\e[1;31mPEEK TEST                FAILED" << endl;
//     }

//     if (SizeTest()) {
        
//         cout << "\e[1;32mSIZE TEST                PASSED" << endl;
//     } else {

//         cout << "\e[1;31mSIZE TEST                FAILED" << endl;
//     }

//     if (EqualityTest()) {

//         cout << "\e[1;32mEQUALITY TEST            PASSED" << endl;
//     } else {

//         cout << "\e[1;31mEQUALITY TEST            FAILED" << endl;
//     }

//     if (InequalityTest()) {

//         cout << "\e[1;32mINEQUALITY TEST          PASSED" << endl;
//     } else {

//         cout << "\e[1;31mINEQUALITY TEST          FAILED" << endl;
//     }

//     if (AssignmentTest()) {

//         cout << "\e[1;32mASSIGNMENT TEST          PASSED" << endl;
//     } else {

//         cout << "\e[1;31mASSIGNMENT TEST          FAILED" << endl;
//     }

//     if (DeleteListTest()) {

//         cout << "\e[1;32mDELETE LIST TEST         PASSED" << endl;
//     } else {

//         cout << "\e[1;31mDELETE LIST TEST         FAILED" << endl;
//     }
    
//     if (AdditionOperatorTest()) {

//         cout << "\e[1;32mADDITION TEST            PASSED" << endl;
//     } else {

//         cout << "\e[1;31mADDITION TEST            FAILED" << endl;
//     }

//     if (AdditionAssignmentTest()) {

//         cout << "\e[1;32mADDITION ASSIGNMENT TEST PASSED" << endl;
//     } else {

//         cout << "\e[1;31mADDITION ASSIGNMENT TEST FAILED" << endl;
//     }

//     if(MergeTest()) {

//         cout << "\e[1;32mMERGE TEST               PASSED" << endl;
//     } else {

//         cout << "\e[1;31mMERGE TEST               FAILED" << endl;
//     }

    
    
//     cout << "\e[1;30m" << endl;

//     // cout << "NODE CREATED COUNT:           ";
//     // cout << Node_Created_Count << endl;

//     // cout << "NODE DESTROYED COUNT:         ";
//     // cout << Node_Destroyed_Count << endl;

//     // cout << "LIST342 CONSTRUCTOR CALLS:     ";
//     // cout << List342_Constructor_Calls << endl;

//     // cout << "LIST342 COPY CONSTRUCTOR CALLS: ";
//     // cout << List342_CopyConstructor_Calls << endl;

//     // cout << "LIST342 DESTRUCTOR CALLS:      ";
//     // cout << List342_Destructor_Calls << endl;

//     return 0;
// }



// // cout << "NODE CREATED COUNT" << endl;
// // cout << Node_Created_Count << endl;

// // cout << "NODE DESTROYED COUNT" << endl;
// // cout << Node_Destroyed_Count << endl;

// // cout << "LIST342 CONSTRUCTOR CALLS" << endl;
// // cout << List342_Constructor_Calls << endl;

// // cout << "LIST342 COPY CONSTRUCTOR CALLS" << endl;
// // cout << List342_CopyConstructor_Calls << endl;

// // cout << "LIST342 DESTRUCTOR CALLS" << endl;
// // cout << List342_Destructor_Calls << endl;

