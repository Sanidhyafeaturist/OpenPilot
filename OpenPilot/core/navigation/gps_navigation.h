#ifndef GPS_NAVIGATION_H
#define GPS_NAVIGATION_H

class GPSNavigation {
public:
    GPSNavigation();
    void updatePosition(float latitude, float longitude);
    void getCurrentPosition(float& latitude, float& longitude);

private:
    float currentLatitude;
    float currentLongitude;
};

#endif // GPS_NAVIGATION_H
