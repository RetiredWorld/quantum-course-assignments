// mainly from qpanda-2: Applications/DJ_Algorithm/DJ_Algorithm.cpp

#include <QPanda.h>
#include <vector>

DJ_Oracle generate_two_qubit_oracle(vector<bool> oracle_function) {
    return [oracle_function](QVec qubit1, Qubit* qubit2) {
        QCircuit prog;
        if (oracle_function[0] == false &&
            oracle_function[1] == true)
        {
            // f(x) = x;
            prog << CNOT(qubit1[0], qubit2);
        }
        else if (oracle_function[0] == true &&
            oracle_function[1] == false)
        {
            // f(x) = x + 1;
            prog << CNOT(qubit1[0], qubit2)
                << X(qubit2);
        }
        else if (oracle_function[0] == true &&
            oracle_function[1] == true)
        {
            // f(x) = 1
            prog << X(qubit2);
        }
        else
        {
            // f(x) = 0, do nothing  
        }
        return prog;
    };
}

void two_qubit_deutsch_jozsa_algorithm(vector<bool> boolean_function)
{
	auto qvm = initQuantumMachine(QMachineType::CPU);
    auto oracle = generate_two_qubit_oracle(boolean_function);
	
	auto prog = deutschJozsaAlgorithm(boolean_function, qvm, oracle);

	cout << convert_qprog_to_originir(prog, qvm);

	auto result = qvm ->directlyRun(prog);
	if (result["c0"] == false)
	{
		cout << "Constant function!" << endl;
	}
	else if (result["c0"] == true)
	{
		cout << "Balanced function!" << endl;
	}
	destroyQuantumMachine(qvm);
}

int main()
{
    std::vector<bool> oracle_function_1({0, 0});
    std::vector<bool> oracle_function_2({1, 0});
    two_qubit_deutsch_jozsa_algorithm(oracle_function_1);
    two_qubit_deutsch_jozsa_algorithm(oracle_function_2);
    return 0;
}

