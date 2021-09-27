int LowPassFilter(int data)
{
    static int y1 = 0, y2 = 0, x[26], n = 12;
    int y0;
    x[n] = x[n+13] = data;
    y0 = (y1<<1) - y2 + x[n] - (x[n+6]<<1) + x[n+12];  //   <<1  means * 2
    y2 = y1;
    y1 = y0;
    y0 >>= 5;  //    y0/=32
    if (--n < 0)
        n = 12;
    return y0;
}

int LowPassFilter2(int ecg)
{
    static int py = 0;
    static int ppy = 0;
    static int ppecg = 0;
    static int pecg = 0;
    int y;
    static int mid = 0;

    const long filt_a0 = 43698;//8775;
    const long filt_a1 = 2745;//17550;
    const long filt_a2 = 43698;//8775;
    const long filt_b1 = 2745;//-50049;
    const long filt_b2 = 21860;//19612;

    if (ecg > mid)
      mid++; else
      mid--;

    ecg -= mid; // to remove DC offset
    y = (filt_a0*ecg + filt_a1*pecg + filt_a2*ppecg - filt_b1*py - filt_b2*ppy) >> 16;
    ppy = py;
    py = y;
    ppecg = pecg;
    pecg = ecg;
    return y + mid;
}

int LowPassFilterMA(int data, int frame)
{
    static int x[64], ptr = 0;
    if (ptr < frame){
        x[ptr] = data;
        ptr++;
        return data;
    }
    x[frame-1] = data;
    int sum = 0;
    for (int i =0; i<frame-1; i++){
        sum += x[i];
        x[i] = x[i+1];

    }
    sum += x[frame-1];
    return sum/frame;
}

int HighPassFilter(int data)
{
    static int y1 = -512, x1 = 0;
    int y = y1 + data - x1;
    int temp = y<<8;
    y = (temp - (y<<4) )>>8;
    x1 = data;
    y1 = y;
    return y;
}


int Differentiate(int data)
{
    static int x1 = 0, x2 = 0, x3 = 0, x4 = 0;
    int x = data;
    x = ((x<<1) + x1 - x3 - (x4<<1))/8;
    x4 = x3;
    x3 = x2;
    x2 = x1;
    x1 = x;
    return x;
}

int MovingAverage(int data)
{
	static int frame[16] = {0};
	static uint8_t ptr = 0;
	static int sum = 0;
	int res;
	
	sum -= frame[ptr];
	sum += data;
	frame[ptr] = data;
	++ptr;
	ptr = ptr & 0x0F;
	res = sum>>4
	return res;
}


























