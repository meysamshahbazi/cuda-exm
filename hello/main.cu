

#include <cuda_runtime.h>
#include <device_launch_parameters.h>
#include <stdio.h>


__global__ void hello_cuda(int i)
{
    i++;
    printf("HEL HEL %d\n",i);
}

int main()
{
    int nx,ny;
    nx = 16;
    ny = 4;
    dim3 block(8,2);
    dim3 grid(nx/block.x, ny/block.y);

    // 
    int i =0;

    hello_cuda<< <grid,block >> > (1);


    cudaDeviceSynchronize();
    cudaDeviceReset();
     
    return 0;
}
 