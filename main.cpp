#include <iostream>
#include <string>
using namespace std;

class Cliente {
private:
    string nome;
    string cpf;
public:
    Cliente(string n, string c) : nome(n), cpf(c) {}

    string getNome() const { return nome; }
    string getCpf() const { return cpf; }
};

class Conta {
private:
    int num;
    double saldo;
    Cliente dono;
public:
    Conta(int n, Cliente d, double s = 0.0) : num(n), dono(d), saldo(s) {}

    void depositar(double valor) {
        if (valor > 0) {
            saldo += valor;
            cout << "Depositado: R$ " << valor << " na conta " << num << endl;
        } else {
            cout << "Valor inválido!" << endl;
        }
    }

    void sacar(double valor) {
        if (valor > 0 && valor <= saldo) {
            saldo -= valor;
            cout << "Sacado: R$ " << valor << " da conta " << num << endl;
        } else {
            cout << "Saldo insuficiente ou valor inválido!" << endl;
        }
    }

    void transferir(double valor, Conta &destino) {
        if (valor > 0 && valor <= saldo) {
            saldo -= valor;
            destino.depositar(valor);
            cout << "Transferido: R$ " << valor << " da conta " << num << " para a conta " << destino.num << endl;
        } else {
            cout << "Saldo insuficiente ou valor inválido!" << endl;
        }
    }

    void transferir(double valor, Conta &dest1, Conta &dest2) {
        if (valor > 0 && valor <= saldo) {
            double valorPorConta = valor / 2;
            saldo -= valor;
            dest1.depositar(valorPorConta);
            dest2.depositar(valorPorConta);
            cout << "Transferido: R$ " << valorPorConta << " para cada conta (" << dest1.num << " e " << dest2.num << ") da conta " << num << endl;
        } else {
            cout << "Saldo insuficiente ou valor inválido!" << endl;
        }
    }

    void mostrarSaldo() const {
        cout << "Saldo da conta " << num << ": R$ " << saldo << endl;
    }

    void mostrarInfo() const {
        cout << "Dono: " << dono.getNome() << ", CPF: " << dono.getCpf() << endl;
        cout << "Conta: " << num << ", Saldo: R$ " << saldo << endl;
    }
};

int main() {
    Cliente cli1("Ana", "111.111.111-11");
    Cliente cli2("Bruno", "222.222.222-22");
    Cliente cli3("Carla", "333.333.333-33");

    Conta conta1(1001, cli1, 1000.0);
    Conta conta2(1002, cli2);
    Conta conta3(1003, cli3);

    conta1.mostrarSaldo();

    conta1.transferir(200.0, conta2);

    conta1.transferir(300.0, conta2, conta3);

    cout << endl;
    conta1.mostrarInfo();
    conta2.mostrarInfo();
    conta3.mostrarInfo();

    return 0;
}