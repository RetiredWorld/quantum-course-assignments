#pragma once

#include <QPanda.h>

#define PI 3.1415926

namespace Homework {

QCircuit QFT(QVec qvec) {
    QCircuit qft = CreateEmptyCircuit();
	auto size = qvec.size();
    for (auto i = 0; i < size; i++) {
        qft << H(qvec[i]);
        for (auto j = i + 1; j < size; j++) {
            qft << CR(qvec[j], qvec[i],
                      2 * PI / (1 << (j - i + 1)));
        }
    }
    return qft;
}

} // namespace Homework

int main(int argc, char** argv) {
    size_t n  = 10;
	if (argc > 1) {
		n = atoi(argv[1]);
	}
    auto qvm  = initQuantumMachine();
    auto qvec = qvm->allocateQubits(n);

    QCircuit circuit = Homework::QFT(qvec);
	cout << convert_qprog_to_originir(circuit, qvm) << endl;
	destroyQuantumMachine(qvm);
	return 0;
}
