#include "voto.h"

#include <stdio.h>

tVoto inicializaVotos() {
  tVoto votos;
  votos.ber = 0;
  votos.brancosM = 0;
  votos.brancosP = 0;
  votos.dij = 0;
  votos.lin = 0;
  votos.lov = 0;
  votos.nulosM = 0;
  votos.nulosP = 0;
  votos.sha = 0;
  votos.tur = 0;
  return votos;
}

float porcentagem(int valor, int total) {
  float p = valor * 100 / total;
  return p;
}

tVoto contabilizaVotoPrisidente(tVoto votos, int votoP) {
  switch (votoP) {
    case DIJKSTRA:
      votos.dij++;
      break;

    case TURING:
      votos.tur++;
      break;

    case SHAW:
      votos.sha++;
      break;

    case BRANCO:
      votos.brancosP++;
      break;

    default:
      votos.nulosP++;
      break;
  }
  return votos;
}

tVoto contabilizaVotoPMinistro(tVoto votos, int votoM) {
  switch (votoM) {
    case BERNERS:
      votos.ber++;
      break;

    case LINUS:
      votos.lin++;
      break;

    case LOVELACE:
      votos.lov++;
      break;

    case BRANCO:
      votos.brancosM++;
      break;

    default:
      votos.nulosM;
      break;
  }
  return votos;
}

int vencedorPresidente(tVoto votos) {
  int d = votos.dij;
  int t = votos.tur;
  int s = votos.sha;
  int b = votos.brancosP + votos.nulosP;

  int vet[4] = {votos.dij, votos.tur, votos.sha, votos.brancosP + votos.nulosP};

  int i, j;

  for (i = 0; i < 4; i++)  // ordena crescente
  {
    for (j = i + 1; j < 3; j++) {
      if (vet[j] > vet[i]) {
        int aux = vet[j];
        vet[j] = vet[i];
        vet[i] = aux;
      }
    }
  }

  for (i = 1; i < 4; i++)  // tie check
  {
    if (vet[0] == vet[i]) {
      return EMPATE;
    }
  }

  if (vet[0] ==
      d) {  // retorna quem for o maior numero, se nao houver empate com o maior
    return DIJKSTRA;
  } else if (vet[0] == t) {
    return TURING;
  } else if (vet[0] == s) {
    return SHAW;
  } else if (vet[0] == b) {
    return SEM_DECISAO;
  }
}

int vencedorPMinistro(tVoto votos) {
  int e = votos.ber;
  int l = votos.lin;
  int o = votos.lov;
  int b = votos.brancosM + votos.nulosP;

  int vet[4] = {votos.ber, votos.lin, votos.lov, votos.brancosM};

  int i, j;

  for (i = 0; i < 4; i++)  // ordena crescente
  {
    for (j = i + 1; j < 3; j++) {
      if (vet[j] > vet[i]) {
        int aux = vet[j];
        vet[j] = vet[i];
        vet[i] = aux;
      }
    }
  }

  for (i = 1; i < 4; i++)  // tie check
  {
    if (vet[0] == vet[i]) {
      return EMPATE;
    }
  }

  if (vet[0] ==
      e) {  // retorna quem for o maior numero, se nao houver empate com o maior
    return BERNERS;
  } else if (vet[0] == l) {
    return LINUS;
  } else if (vet[0] == o) {
    return LOVELACE;
  } else if (vet[0] == b) {
    return SEM_DECISAO;
  }
}

int obtemTotalVotosPresidente(tVoto votos) {  // branco conta??
  return votos.dij + votos.tur + votos.sha + votos.nulosP;
}

int obtemTotalVotosPMinistro(tVoto votos) {
  return votos.ber + votos.lin + votos.lov + votos.nulosM;
}

void printaResultado(tVoto votos, int totalP, int totalM, int vencedorP,
                     int vencedorM, int counterQtd, int qtd) {
  printf("FIM DA ELEICAO\n");
  if (vencedorP = DIJKSTRA) {
    printf(
        "- PRESIDENTE ELEITO: Edsger Dijkstra (Partido do Melhor Caminho "
        "(PMC)), %d, %.2f%%",
        votos.dij, porcentagem(votos.dij, counterQtd));

  } else if (vencedorP = TURING) {
    printf(
        "- PRESIDENTE ELEITO: Alan Turing (Partido dos Avanco Intelectual "
        "(PAI)), %d, %.2f%%",
        votos.tur, porcentagem(votos.tur, counterQtd));

  } else if (vencedorP = SHAW) {
    printf(
        "- PRESIDENTE ELEITO: Carol Shaw (Mulheres Programadoras Unidas "
        "(MPU)), %d, %.2f%%",
        votos.sha, porcentagem(votos.sha, counterQtd));

  } else if (vencedorP = SEM SEM_DECISAO) {
    printf("- PRESIDENTE ELEITO: SEM DECISAO");

  } else if (vencedorP = EMPATE) {
    printf("- PRESIDENTE ELEITO: EMPATE");
  }

  printf("\n");
  printf("- COMPARECIMENTO: %.2f%%", porcentagem(counterQtd, qtd));
  printf("\n");
  
  printf("- NULOS E BRANCOS: %d,%d", votos.nulosP +votos.brancosP, votos.brancosM + votos.nulosM);
  printf("\n");
}
