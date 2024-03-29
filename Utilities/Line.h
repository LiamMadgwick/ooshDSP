/*

    Line
    DAISYsp

*/

class line
{
public:
    line()  {}
    ~line() {}
    
    void Init(float sample_rate)
    {
        sample_rate_ = sample_rate;
        dur_         = 0.5f;
        end_         = 0.0f;
        start_       = 1.0f;
        val_         = 1.0f;
    }
    
    //start - beginning value, end - ending value, dur - duration in seconds
    void Start(float start, float end, float dur)
    {
        start_    = start;
        end_      = end;
        dur_      = dur;
        inc_      = (end - start) / (sample_rate_ * dur_);
        val_      = start_;
        finished_ = 0;
    }
    
    float Process(uint8_t *finished)
    {
        float out;
        out = val_;

        if((end_ > start_ && out >= end_) || (end_ < start_ && out <= end_))
        {
            finished_ = 1;
            val_      = end_;
            out       = end_;
        }
        else
        {
            val_ += inc_;
        }
        *finished = finished_;
        return out;
    }
    
private:
    float start_, end_, dur_;
    float inc_, val_, sample_rate_;
    uint8_t finished_;
};
