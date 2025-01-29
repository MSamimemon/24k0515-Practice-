
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Sensor
{
    float nutrients;
    int phlevel;
    float pestactivity;
    
};

struct Equipment
{
    char tractors[100];
    char Operationstetus[100];
    float fuellevel;
    char schedule[100];
    
    
    
};

struct Weather
{
    float expecttemperature;
    float expectrainfall;
    char windpatterns[100];
 
};

struct Crop
{
    char croptype[100];
    char growthstage[100];
    float expectedyield;
    
     struct Weather *weather;
};
struct Field
{
    float latitude;
    float longitude;
    float soilhealthmetric;
    float moisturerate;
    
    struct Crop *crops;
    struct Equipment *equipment;
    struct Sensor*sensors;
    
    
    
};

struct RegionalHub {
    struct Field *fields;
    char regionname[100];
    int totalfields;
    
};

void enterfieldinfo(struct Field *fields, int totalfields);
void Allfreefields(struct Field *fields, int totalfields);
void regionalhubinfo(struct RegionalHub *hub);
void freeupregionalhub(struct RegionalHub *hub);
void freeupfields(struct Field *fields, int totalfields);
int main() {
    struct RegionalHub hub;
    regionalhubinfo(&hub);
  

    return 0;
}

void regionalhubinfo(struct RegionalHub *hub)
{
    printf("enter the region name ");
    scanf("%s", hub->regionname);
    printf("enter the total number of fields in the region ");
    scanf("%d", &hub->totalfields);

    hub->fields = (struct Field *)malloc(hub->totalfields * sizeof(struct Field));

    enterfieldinfo(hub->fields, hub->totalfields);
}

void freeupregionalhub(struct RegionalHub *hub)
 {
   freeupfields(hub->fields,hub-> totalfields);
    free(hub->fields);
}

void Allfreefields(struct Field *fields, int totalfields)
 {
    for (int i = 0; i < totalfields; i++) {
        free(fields[i].crops);
        free(fields[i].equipment);
        free(fields[i].sensors);
        for (int j = 0; j < totalfields; j++) {
            free(fields[i].crops[j].weather);
        }
    }
}
void enterfieldinfo(struct Field fields[],int totalfields)
{
    for(int i =0; i< totalfields;i++)
    {
        printf("enter details for field %d ",i+1);
        printf("enter latitude ");
        scanf("%f",&fields[i].latitude);
        printf("enter longitude ");
        scanf("%f",&fields[i].longitude);
        printf("enter soil health matric  ");
        scanf("%f",&fields[i].soilhealthmetric);
        printf("enter moisturerate  ");
        scanf("%f",&fields[i].moisturerate);
        int totalcrop;
        printf("enter total crops info :");
        scanf("%d",&totalcrop);
        
        fields[i].crops = (struct Crop* )malloc(sizeof(struct Crop)*totalcrop);
        for(int j =0; j< totalcrop;j++)
        {
            printf("Enter crop type :");
            scanf("%s",fields[i].crops[j].croptype);
            printf("Enter growth stage :");
            scanf("%s",fields[i].crops[j].growthstage);
            printf("Enter crop type :");
            scanf("%f",&fields[i].crops[j].expectedyield);
            
        
        int totalweather;
        printf("enter total weather ");
        scanf("%d",&totalweather);
        
        fields[i].crops[j].weather = (struct Weather*)malloc(sizeof(struct Weather)*totalweather);
        for(int y = 0; y < totalweather; y++)
        {
            printf("weather info is %d",y+1);
            printf("enter expected temperature ");
            scanf("%f",&fields[i].crops[y].weather[y].expecttemperature);
            printf("enter expected rainfall according to situation  ");
            scanf("%f",&fields[i].crops[y].weather[y].expectrainfall);
            printf("enter expected wind patterns  ");
            scanf("%s",fields[i].crops[j].weather[y].windpatterns);
            
            
        }
        }
        int totalequipment;
        printf("Enter total equipment for field %d: ", i + 1);
        scanf("%d", &totalequipment);
        fields[i].equipment = (struct Equipment *)malloc(totalequipment * sizeof(struct Equipment));
        for (int k = 0; k < totalequipment; k++) {
            printf("enter equipment type for equipment %d ", k + 1);
            scanf("%s", fields[i].equipment[k].tractors);
            printf("enter operational status for equipment %d ", k + 1);
            scanf("%s", fields[i].equipment[k].Operationstetus);
            printf("enter fuel level for equipment %d ", k + 1);
            scanf("%f", &fields[i].equipment[k].fuellevel);
            printf("enter schedule for equipment %d ", k + 1);
            scanf("%s", fields[i].equipment[k].schedule);
        }

        int totalsensors;
        printf("enter total sensors for field %d ", i + 1);
        scanf("%d", &totalsensors);
        fields[i].sensors = (struct Sensor *)malloc(totalsensors * sizeof(struct Sensor));
        for (int l = 0; l < totalsensors; l++) {
            printf("enter nutrient level for sensor %d ", l + 1);
            scanf("%f", &fields[i].sensors[l].nutrients);
            printf("enter pH level for sensor %d ", l + 1);
            scanf("%d", &fields[i].sensors[l].phlevel);
            printf("enter pest activity for sensor %d ", l + 1);
            scanf("%f", &fields[i].sensors[l].pestactivity);
        }

        
    }
    
}


void freeupfields(struct Field *fields, int totalfields) {
    for (int i = 0; i < totalfields; i++) {
        free(fields[i].crops);
        free(fields[i].equipment);
        free(fields[i].sensors);
        for (int j = 0; j < totalfields; j++) {
            free(fields[i].crops[j].weather);
        }
    }
}