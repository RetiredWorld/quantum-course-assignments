// mainly from qpanda-2: Applications/HHL_Algorithm/HHL_Algorithm.cpp

#include <QPanda.h>


static bool HHL_test_fun() {
	auto machine = initQuantumMachine(CPU);

	QStat A = {
	qcomplex_t(15.0 / 4.0, 0), qcomplex_t(9.0 / 4.0, 0), qcomplex_t(5.0 / 4.0, 0), qcomplex_t(-3.0 / 4.0, 0),
	qcomplex_t(9.0 / 4.0, 0), qcomplex_t(15.0 / 4.0, 0), qcomplex_t(3.0 / 4.0, 0), qcomplex_t(-5.0 / 4.0, 0),
	qcomplex_t(5.0 / 4.0, 0), qcomplex_t(3.0 / 4.0, 0), qcomplex_t(15.0 / 4.0, 0), qcomplex_t(-9.0 / 4.0, 0),
	qcomplex_t(-3.0 / 4.0, 0), qcomplex_t(-5.0 / 4.0, 0), qcomplex_t(-9.0 / 4.0, 0), qcomplex_t(15.0 / 4.0, 0)
	};

	std::vector<double> b = { 0.5, 0.5, 0.5, 0.5 };
	cout << A << endl;
	for (double i : b) {
		cout << " " << i;
	}
	cout << endl << "\n\n";

	auto prog = QProg();
	QCircuit hhl_cir = build_HHL_circuit(A, b, machine);
	prog << hhl_cir;

	cout << convert_qprog_to_originir(prog, machine) << endl;
	directlyRun(prog);
	auto stat = machine->getQState();
	machine->finalize();
	stat.erase(stat.begin(), stat.begin() + (stat.size() / 2));

	// normalise
	double norm = 0.0;
	for (auto &val : stat)
	{
		norm += ((val.real() * val.real()) + (val.imag() * val.imag()));
	}
	norm = sqrt(norm);

	QStat stat_normed;
	for (auto &val : stat)
	{
		stat_normed.push_back(val / qcomplex_t(norm, 0));
	}

	for (auto &val : stat_normed)
	{
		qcomplex_t tmp_val((abs(val.real()) < MAX_PRECISION ? 0.0 : val.real()), (abs(val.imag()) < MAX_PRECISION ? 0.0 : val.imag()));
		val = tmp_val;
	}

	cout << "\n\nresult:" << endl;
	//get solution
	QStat result;
	for (size_t i = 0; i < b.size(); ++i)
	{
		result.push_back(stat_normed.at(i));
	}

	int w = 0;
	double coffe = sqrt(340);
	for (auto &val : result)
	{
		val *= coffe;
		std::cout << val << " ";
		if (++w == 2)
		{
			w = 0;
			cout << endl;
		}
	}
	cout << endl;

	return true;
}

int main()
{
	try
	{
	   HHL_test_fun();
	}
	catch (const std::exception& e)
	{
		cerr << "HHL running error: got a exception: " << e.what() << endl;
	}
	catch (...)
	{
		cerr << "HHL running error: unknow exception." << endl;
	}

	return 0;
}
