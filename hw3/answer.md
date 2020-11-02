## 如何理解Oracle
- hidden subgroup problem(DJ algorithm): 将同一coset的元素映射到相应值，即$G \mapsto G/X$, X为解集子群。如果将$X$看作$\ker f$, 那么从$G/X = G/ \ker f = \im f$也可看出f的作用。
- Grover search: 通过其几何意义理解。
## HHL 算法的方程是怎么编码到量子线路中的
HHL algorithm solves the linear equation of the form $$Ax=b$$ in which $A$ and $b$ are assumed instant access by quantum circuit.
 
 Standard HHL algorithm contains
 1. Conditional Hamiltonian evolution $\sum _ \tau | \tau \rangle \langle \tau | \otimes e ^{i A \tau t_0 /T}$ on $|\Psi_0\rangle \otimes |b\rangle$
 2. Quantum FFT
 3. Quantum Conditional Rotation

we will now focus on how the equation is encoded in the quantum circuit

The vector $b$ is encoded in the first step by simply amplitude encoding in $|b\rangle$. That is, every element $b_i$ is proportional to the ampltude of $\langle i | b \rangle$

The only step we explicitly use matrix $A$ is also the first step, where a quantum operator of the form $e^{iA x}$ is required. Thus, in QPanda, classical matrix $A$ is processed into C++ package *eigen* using `HHLAlg::transform_hermitian_to_unitary_mat` method and efficient classical calculation of $e^{iA x}$ is made before conditional hamiltonian evolution is processed into `build_QPE_circuit` method, which is contained in `QAlg/Base_QCircuit/QPE.h`. 
