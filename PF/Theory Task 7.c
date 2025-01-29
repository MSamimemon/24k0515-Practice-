#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
    char title[100];
    double rating;
    int runtime; 
    char encodingFormat[20];
}ContentMetadata;


double** createEngagementMatrix(int numUsers,int numCategories){
    double** matrix=(double**)malloc(numUsers*sizeof(double*));
    for(int i=0;i<numUsers;i++){
        matrix[i]=(double*)malloc(numCategories*sizeof(double));
        for(int j=0;j<numCategories;j++){
            matrix[i][j]=(i+1)*(j+1)*0.5; 
        }
    }
    return matrix;
}


void*** createDeviceMatrix(int numUsers,int numDevices){
    void*** matrix=(void***)malloc(numUsers*sizeof(void**));
    for(int i=0;i<numUsers;i++){
        matrix[i]=(void**)malloc(numDevices*sizeof(void*));
        for(int j=0;j<numDevices;j++){
            double* settings=(double*)malloc(3*sizeof(double)); 
            settings[0]=1080.0; 
            settings[1]=j*2.5;
            settings[2]=5.0+j;
            matrix[i][j]=settings;
        }
    }
    return matrix;
}


void*** createContentMatrix(int numCategories,int numContentPerCategory){
    void*** matrix=(void***)malloc(numCategories*sizeof(void**));
    for(int i=0;i<numCategories;i++){
        matrix[i]=(void**)malloc(numContentPerCategory*sizeof(void*));
        for(int j=0;j<numContentPerCategory;j++){
            ContentMetadata* metadata=(ContentMetadata*)malloc(sizeof(ContentMetadata));
            snprintf(metadata->title,100,"Content%d-%d", i+1,j+1);
            metadata->rating=4.0+(i + j) * 0.1;
            metadata->runtime=90+j*10;
            snprintf(metadata->encodingFormat,20,"H.264");
            matrix[i][j]=metadata;
        }
    }
    return matrix;
}


void freeEngagementMatrix(double** matrix,int numUsers){
    for(int i=0;i<numUsers;i++){
        free(matrix[i]);
    }
    free(matrix);
}


void freeDeviceMatrix(void*** matrix,int numUsers,int numDevices){
    for(int i=0; i<numUsers;i++){
        for(int j=0;j<numDevices;j++){
            free(matrix[i][j]);
        }
        free(matrix[i]);
    }
    free(matrix);
}

void freeContentMatrix(void*** matrix,int numCategories,int numContentPerCategory){
    for(int i=0;i<numCategories;i++){
        for(int j =0;j<numContentPerCategory;j++){
            free(matrix[i][j]);
        }
        free(matrix[i]);
    }
    free(matrix);
}


void displaySystemInfo(double** engagementMatrix, void*** deviceMatrix, void*** contentMatrix,int numUsers, int numCategories, int numDevices, int numContentPerCategory){
    printf("Engagement Matrix:\n");
    for (int i = 0; i < numUsers; i++) {
        for (int j = 0; j < numCategories; j++) {
            printf("%.2f ", engagementMatrix[i][j]);
        }
        printf("\n");
    }

    printf("\nDevice Matrix:\n");
    for (int i = 0; i < numUsers; i++) {
        for (int j = 0; j < numDevices; j++) {
            double* settings = (double*)deviceMatrix[i][j];
            printf("User %d, Device %d: Resolution %.0fp, Playback %.2f hrs, Bandwidth %.2f Mbps\n",
                   i + 1, j + 1, settings[0], settings[1], settings[2]);
        }
    }

    printf("\nContent Metadata:\n");
    for (int i = 0; i < numCategories; i++) {
        for (int j = 0; j < numContentPerCategory; j++) {
            ContentMetadata* metadata = (ContentMetadata*)contentMatrix[i][j];
            printf("Category %d, Content %d: Title: %s, Rating: %.1f, Runtime: %d min, Format: %s\n",
                   i + 1, j + 1, metadata->title, metadata->rating, metadata->runtime, metadata->encodingFormat);
        }
    }
}

int main(){
    
    int numUsers;       
    int numCategories;   
    int numDevices;      
    int numContentPerCategory; 

    printf("Enter Number Of Users: ");
    scanf("%d",&numUsers);
    printf("Enter Number Of Categories: ");
    scanf("%d",&numCategories);
    printf("Enter Number Of Devices: ");
    scanf("%d",&numDevices);
    printf("Enter Number Of Content Per Category: ");
    scanf("%d",&numContentPerCategory);

    
    double** engagementMatrix=createEngagementMatrix(numUsers,numCategories);
    void*** deviceMatrix=createDeviceMatrix(numUsers,numDevices);
    void*** contentMatrix=createContentMatrix(numCategories,numContentPerCategory);
    displaySystemInfo(engagementMatrix,deviceMatrix,contentMatrix,numUsers,numCategories,numDevices, numContentPerCategory);
    freeEngagementMatrix(engagementMatrix,numUsers);
    freeDeviceMatrix(deviceMatrix,numUsers,numDevices);
    freeContentMatrix(contentMatrix,numCategories,numContentPerCategory);

    return 0;
}

