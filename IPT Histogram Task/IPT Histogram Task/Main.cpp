#include <iostream>
#include <vector>
#include <utility>
#include <numeric>
#include <algorithm>
#include <string>
#include <iterator>


// Namespace declarations.
using namespace std;


bool In_Range(unsigned low, unsigned high, unsigned x) // Function to check whether a number is between a certain range.
{
	bool Answer;
	Answer = low <= x && x <= high; // Check if X is between Low and High.
	return Answer;
}

template <typename T>
void Output_Vector(T& Marks_Vector) // Outputs contents of vector.
{
	// Declaration of counts.
	auto Count_0_To_29 = 0;
	auto Count_30_To_39 = 0;
	auto Count_40_To_69 = 0;
	auto Count_70_To_100 = 0;
	
	//Declaration of the asterisk.
	auto Star = "*";

	for (const auto& Student_Mark : Marks_Vector)
	{
		// const on classes means you cannot modify members

		/*DEBUG CODE :
		cout << "Output : ";
		cout << Marks_Vector[i] << endl;*/

		//Check the ranges of the marks and add to count if true.
		In_Range(0, 29, Student_Mark) ? ++Count_0_To_29 :
			1;
		In_Range(30, 39, Student_Mark) ? ++Count_30_To_39 :
			1;
		In_Range(40, 69, Student_Mark) ? ++Count_40_To_69 :
			1;
		In_Range(70, 100, Student_Mark) ? ++Count_70_To_100 :
			1;
	}

	// Declaration of string literals showing the number ranges.
	auto Buffer_One = "0 - 29 : ";
	auto Buffer_Two = "30 - 39 : ";
	auto Buffer_Three = "40 - 69 : ";
	auto Buffer_Four = "70 - 100 : ";

	// Creation and assignment of a vector with pairs of type string and int.
	vector<pair <string, int>> Grade_Boundary_Mark_Count = { {Buffer_One, Count_0_To_29}, {Buffer_Two, Count_30_To_39}
															,{Buffer_Three, Count_40_To_69}, {Buffer_Four, Count_70_To_100} };

	float Histogram_Scale = 1.f; // Scale ratio of histogram, Current scale - 1 : 1
	
	for (const auto& Mark_Count : Grade_Boundary_Mark_Count) // Output the Histogram.
	{
		int Histogram_Bar_Length = Mark_Count.second * Histogram_Scale;

		cout << Mark_Count.first;
		for (int i = 0; i < Histogram_Bar_Length; i++)
		{
			cout << Star;
		}

		cout << "\n";
	}

	// Output Average mark
	// Average = sum of inputs in the vector / total number of inputs in the vector
	float Average = accumulate(Marks_Vector.begin(), Marks_Vector.end(), 0.0) / Marks_Vector.size();
	cout << "The average mark is : " << Average << endl;

	//Output Lowest Mark
	int Lowest_Mark = *min_element(Marks_Vector.begin(), Marks_Vector.end());
	cout << "The lowest mark is : " << Lowest_Mark << endl;
	
	//Output Highest Mark
	int Highest_Mark = *max_element(Marks_Vector.begin(), Marks_Vector.end());
	cout << "The highest mark is : " << Highest_Mark << endl;
	
	//Output Passing Mark
	//int Passing_Mark;
	//int Pass_Count = 0;
	
	//cout << "Enter the passing mark : " << endl;
	//cin >> Passing_Mark;
	
	// check if elements of the vector are greater or equal to the passing mark.

	//cout << Pass_Count << " Students passed." << endl;
}

int main()
{
	int User_Input; // Stores the mark of the student.
	int No_of_Students; // Stores the number of students.
	vector<int> Marks_Vector; // Creates a new vector.


	cout << "Enter the number of students : " << endl;

	cin >> No_of_Students; // Number of student the teacher will input total grades for.

	cout << "Enter the student's mark : " << endl;

	for (int i = 0; i < No_of_Students; i++) // Takes in user input.
	{
		cin >> User_Input;
		Marks_Vector.push_back(User_Input); // Pushes to vector.
	}

	// Implicit Deduction of type int
	Output_Vector(Marks_Vector); // Runs the Output_Vector template.

	int a; cin >> a; // Debugging freeze
	return EXIT_SUCCESS;
}