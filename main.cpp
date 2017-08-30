#include <stdio.h>
#include <omp.h>

int main(int argc, char *argv[]) {
  int iam = 0, np = 1;

#ifdef _OPENMP
  #pragma omp parallel default(shared) private(iam, np)
  {
    np = omp_get_num_threads();
    iam = omp_get_thread_num();
    printf("Hello from thread %d out of %d\n", iam, np);
  }
#else
  printf("NO OpenMP support found for your compiler!");
#endif
}
