//#include "myDLL.h"
//
//int main()
//{
//	int a = 1;
//	myDLL obj;
//	do {
//		cout << "Press 1: if you wanted to add patient " << endl;
//		cout << "Press 2: if you wanted to remove patient " << endl;
//		cout << "Press 3: if you wanted to Count total Patient " << endl;
//		cout << "Press 4: if you wanted to Display patient " << endl;
//		cout << "Press 0: if you wanted to Exit the program " << endl;
//		cin >> a;
//		if (a == 1) {
//			int b;
//			cout << "Enter Patient ID :";
//			cin >> b;
//			obj.insertAtTail(b);
//		}
//		else if (a == 2) {
//			cout << "Press 1 :if you are checked " << endl;
//			cout << "Press 2 :if you are wanted to cancel " << endl;
//			int c;
//			cin >> c;
//			if (c == 1) {
//				obj.deleteFromHead();
//			}
//			else if (c == 2) {
//				int id;
//				cout << "enter your id";
//				cin >> id;
//				obj.deleteValue(id);
//			}
//		}
//	    else if (a == 3) {
//			cout << "The total number of nodes " << obj.count() << endl;
//		}
//		else if (a == 4) {
//			obj.displayFromHead();
//		}
//		else if (a == 0) {
//			cout << "Existing program" << endl;
//			break;
//		}
//		else {
//			cout << "enter a valid number" << endl;
//		}
//
//	} while (a != 0);
//
//	return 0;
//}