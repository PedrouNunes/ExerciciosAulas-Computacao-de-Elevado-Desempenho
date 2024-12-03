// Define a versão mínima requerida para o CMake
cmake_minimum_required(VERSION 3.22) 

// Nomeia o projeto "ced" e especifica que usa a linguagem C++
project(ced LANGUAGES CXX) 

// Busca e adiciona suporte ao toolkit CUDA (caso seja usado)
find_package(CUDAToolkit) 

// Adiciona flags de compilação: 
//  `-fopenmp`: habilita suporte a paralelismo com OpenMP
//  `-O3`: otimizações agressivas de performance
set(CMAKE_CXX_FLAGS "-fopenmp -O3") 

// Cria um executável chamado "farao" utilizando os arquivos indicados
add_executable(farao
    farao.cpp
    heat_diffusion_2d.cpp
    farao.h
)
