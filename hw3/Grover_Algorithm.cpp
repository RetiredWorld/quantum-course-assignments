// mainly from qpanda-2: Applications/Grover_Algorithm/Grover_Algorithm.cpp


#include <QPanda.h>


void grover_test1()
{
	auto machine = initQuantumMachine(CPU);
	auto x = machine->allocateCBit();

	try
	{
		std::vector<SearchDataByUInt> search_sapce;
		search_sapce.push_back(8);
		search_sapce.push_back(7);
		search_sapce.push_back(6);
		search_sapce.push_back(0);
		search_sapce.push_back(6);
		search_sapce.push_back(3);
		search_sapce.push_back(6);
		search_sapce.push_back(4);
		search_sapce.push_back(7);
		search_sapce.push_back(8);
		search_sapce.push_back(5);
		search_sapce.push_back(11);
		search_sapce.push_back(3);
		search_sapce.push_back(10);
		search_sapce.push_back(0);
		search_sapce.push_back(7);

		std::vector<size_t> result_index_vec;

		//test
		size_t indexx = 0;
		for (const auto &item : search_sapce)
		{
			if (item == SearchDataByUInt(6))
			{
				result_index_vec.push_back(indexx);
			}
			++indexx;
		}

		//for check grover search result
		cout << "The target result's index:" << endl;
		for (const auto &result_item : result_index_vec)
		{
			cout << result_item << " ";
		}
		cout << endl;
		result_index_vec.clear();

		cout << "Start grover search algorithm:" << endl;
		QProg grover_Qprog = grover_alg_search_from_vector(search_sapce, x == 6, result_index_vec, machine, 4);

		//grover result
		cout << "The result's index:" << endl;
		for (const auto &result_item : result_index_vec)
		{
			cout << result_item << " ";
		}

		cout << "\n\n" << convert_qprog_to_originir(grover_Qprog, machine) << endl;
	}
	catch (const std::exception& e)
	{
		cout << "Error:Catch an exception: " << e.what() << endl;
	}
	catch (...)
	{
		cout << "Error: Catch a unknow exception." << endl;
	}

	destroyQuantumMachine(machine);
}

int main()
{
	grover_test1();

	return 0;
}
