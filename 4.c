#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<locale.h>

// Luciano dos Santos Nascimento

int dentro_int(int x0, int y0, int x1, int y1, int x, int y){
    int valor = 0;
    if(x > x0 && x < x1){
        if(y > y0 && y < y1){
            valor = 1;
        }
    }
    return valor;
}

int primo(int n){
    int i = 0, div = 0,valor = 0, vetor[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    for(i = 0; i < 10; i++){
        div = n%vetor[i];
        if(div == 0){
            if(n == vetor[i]){
                valor = 1;
            }
        }
    }
    return valor;
}

int fibonaac(int x){
    if(x == 0 || x == 1){
        return x;
    }else{
        return fibonaac( x - 1) + fibonaac(x - 2);
    }

}


int soma_impares(int n){
    int valor = 0, i = 0, resultado = 0;
    for(i = 0; i < n*2; i++){
        valor = i%2;
        if(valor != 0){
            resultado += i;
        }
        
    }
    return resultado;
}

double pi(int n){
    double resultado = 0.0, numerador = 0 ;
    for(int i = 0; i < n; i++){
        numerador = pow(-1, i);
        resultado += 4.0*((numerador)/((2*i) + 1));
    }
    return resultado;
}


float raizes(float a, float b, float c, float *x1, float *x2){
    float t = pow(b, 2);
    float teste = sqrt( t - 4*a*c);
    float numero = 0.0;

    if(teste == 0.0){
        *x1 = (b*(-1.0) - teste)/(2.0*a);
        numero = 1.0;

    }
    else if(teste > 0.0){
       
        *x1 = (b*(-1.0) - teste)/(2.0*a);
        *x2 = (b*(-1.0) + teste)/(2.0*a);
        numero = 2.0;
 
    }
    return numero;
}

void calc_esfera (float r, float* area, float* volume){
    float potencia = pow(r, 2);
    float potencia2 = pow(r, 3);
    *volume = 4 * potencia;
    *area = (4*potencia2)/3;

}

int negativos(int n, float* vet){
    int contador = 0, i =0;
    for(i = 0; i < n; i++){
    if (vet[i] < 0)
    {
        contador++;
    }
    }
    return contador;
}

int pares(int n, int* vet){
    int contador = 0, i =0;
    for(i = 0; i < n; i++){
    if (vet[i]%2 == 0)
    {
        contador++;
    }
    }
    return contador;

}
void inverte (int n, int* vet){
    int i = 0, temp = 0, diferanca =0;
    int p = n - 1;
    for(i = 0; i < n/2; i++){
        temp = vet[i];
        diferanca = p - i;
        vet[i] = vet[diferanca];
        vet[diferanca] = temp;
    }
}











int main() {
	setlocale(LC_ALL, "Portuguese");
	
    // Teste para função dentro_int
    printf("Teste para função dentro_int:\n");
    int dentro = dentro_int(0, 0, 10, 10, 5, 5);
    printf("Ponto dentro do retângulo? %s\n\n", dentro ? "Sim" : "Não");

    // Teste para função primo
    printf("Teste para função primo:\n");
    int numero = 5;
    int ehPrimo = primo(numero);
    printf("%d é primo? %s\n\n", numero, ehPrimo ? "Sim" : "Não");

    // Teste para função fibonaac
    printf("Teste para função fibonaac:\n");
    int posicao = 6;
    int resultado_fib = fibonaac(posicao);
    printf("Fibonacci de %d: %d\n\n", posicao, resultado_fib);

    // Teste para função soma_impares
    printf("Teste para função soma_impares:\n");
    int n = 5;
    int soma = soma_impares(n);
    printf("Soma dos primeiros %d ímpares: %d\n\n", n, soma);

    // Teste para função pi
    printf("Teste para função pi:\n");
    int iteracoes = 1000;
    double pi_aproximado = pi(iteracoes);
    printf("Aproximação de PI com %d iterações: %.10f\n\n", iteracoes, pi_aproximado);

    // Teste para função raizes
    printf("Teste para função raizes:\n");
    float a = 1, b = -3, c = 2;
    float x1, x2;
    int num_raizes = raizes(a, b, c, &x1, &x2);
    if (num_raizes == 1) {
        printf("Raiz única: x1 = %.2f\n\n", x1);
    } else if (num_raizes == 2) {
        printf("Duas raízes: x1 = %.2f, x2 = %.2f\n\n", x1, x2);
    } else {
        printf("Não há raízes reais.\n\n");
    }

    // Teste para função calc_esfera
    printf("Teste para função calc_esfera:\n");
    float raio = 3.0;
    float area, volume;
    calc_esfera(raio, &area, &volume);
    printf("Área da superfície da esfera: %.2f, Volume: %.2f\n\n", area, volume);

    // Teste para função negativos
    printf("Teste para função negativos:\n");
    float vet1[] = {1.5, -2.3, -4.1, 0.5};
    int num_negativos = negativos(4, vet1);
    printf("Número de elementos negativos: %d\n\n", num_negativos);

    // Teste para função pares
    printf("Teste para função pares:\n");
    int vet2[] = {1, 2, 3, 4, 5, 6};
    int num_pares = pares(6, vet2);
    printf("Número de elementos pares: %d\n\n", num_pares);

    // Teste para função inverte
    printf("Teste para função inverte:\n");
    int vet3[] = {1, 2, 3, 4, 5};
    int tamanho_vet3 = 5;
    inverte(tamanho_vet3, vet3);
    printf("Vetor invertido: ");
    for (int i = 0; i < tamanho_vet3; i++) {
        printf("%d ", vet3[i]);
    }
    printf("\n\n");

    return 0;
}
