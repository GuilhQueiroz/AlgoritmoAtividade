//
// Created by guilh-queiroz on 19/11/24.
//
#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>

// Estrutura para armazenar os pedidos
struct Pedido {
    int id;
    std::string descricao;
    bool vip;

    // Construtor
    Pedido(int id, const std::string& descricao, bool vip) : id(id), descricao(descricao), vip(vip) {}
};

// Função para comparar pedidos VIP
struct CompararPedidos {
    bool operator()(const Pedido& p1, const Pedido& p2) {
        if (p1.vip != p2.vip) {
            return !p1.vip; // VIP tem maior prioridade
        }
        return p1.id > p2.id;
    }
};

class GerenciamentoPedidos {
private:
    std::priority_queue<Pedido, std::vector<Pedido>, CompararPedidos> filaPrioridade; // Fila de prioridade para VIPs
    std::queue<Pedido> filaComum; // Fila normal para clientes comuns
    std::unordered_map<int, bool> pedidosCancelados; // Map para rastrear pedidos cancelados

public:
    // Adicionar um novo pedido
    void adicionarPedido(int id, const std::string& descricao, bool vip) {
        Pedido novoPedido(id, descricao, vip);
        if (vip) {
            filaPrioridade.push(novoPedido);
        } else {
            filaComum.push(novoPedido);
        }
        std::cout << "Pedido adicionado: " << descricao << (vip ? " [VIP]" : " [Comum]") << std::endl;
    }

    // Processar o próximo pedido
    void processarPedido() {
        if (!filaPrioridade.empty()) {
            Pedido proximoPedido = filaPrioridade.top();
            filaPrioridade.pop();
            if (pedidosCancelados[proximoPedido.id]) {
                std::cout << "Pedido #" << proximoPedido.id << " foi cancelado. Ignorando." << std::endl;
                return;
            }
            std::cout << "Processando pedido VIP #" << proximoPedido.id << ": " << proximoPedido.descricao << std::endl;
        } else if (!filaComum.empty()) {
            Pedido proximoPedido = filaComum.front();
            filaComum.pop();
            if (pedidosCancelados[proximoPedido.id]) {
                std::cout << "Pedido #" << proximoPedido.id << " foi cancelado. Ignorando." << std::endl;
                return;
            }
            std::cout << "Processando pedido comum #" << proximoPedido.id << ": " << proximoPedido.descricao << std::endl;
        } else {
            std::cout << "Não há pedidos para processar." << std::endl;
        }
    }

    // Visualizar todos os pedidos sem removê-los
    void visualizarPedidos() {
        std::cout << "Pedidos VIPs pendentes:" << std::endl;
        std::priority_queue<Pedido, std::vector<Pedido>, CompararPedidos> copiaFilaPrioridade = filaPrioridade;
        while (!copiaFilaPrioridade.empty()) {
            Pedido p = copiaFilaPrioridade.top();
            copiaFilaPrioridade.pop();
            std::cout << "ID: " << p.id << ", Descrição: " << p.descricao << " [VIP]" << std::endl;
        }

        std::cout << "Pedidos comuns pendentes:" << std::endl;
        std::queue<Pedido> copiaFilaComum = filaComum;
        while (!copiaFilaComum.empty()) {
            Pedido p = copiaFilaComum.front();
            copiaFilaComum.pop();
            std::cout << "ID: " << p.id << ", Descrição: " << p.descricao << " [Comum]" << std::endl;
        }
    }

    // Remover um pedido cancelado
    void cancelarPedido(int id) {
        pedidosCancelados[id] = true;
        std::cout << "Pedido #" << id << " foi cancelado." << std::endl;
    }

    // Atualizar a prioridade de um pedido para VIP
    void atualizarPrioridade(int id, const std::string& descricao) {
        filaPrioridade.push(Pedido(id, descricao, true));
        std::cout << "Pedido #" << id << " atualizado para VIP." << std::endl;
    }
};

int main() {
    GerenciamentoPedidos sistema;

    sistema.adicionarPedido(1, "Café Expresso", false);
    sistema.adicionarPedido(2, "Capuccino", true);
    sistema.adicionarPedido(3, "Latte", false);

    sistema.visualizarPedidos();

    sistema.processarPedido();
    sistema.cancelarPedido(1);
    sistema.processarPedido();

    sistema.atualizarPrioridade(3, "Latte Atualizado");

    sistema.visualizarPedidos();
    sistema.processarPedido();

    return 0;
}