package hu.elte.madtycoon.ui;

import hu.elte.madtycoon.core.Builder;
import hu.elte.madtycoon.core.Statistics;
import hu.elte.madtycoon.objects.Building;
import hu.elte.madtycoon.utils.Vector2I;

public interface IEngine
{
    /**
     * @return The world budget.
     */
    int getMoney();

    /**
     * @return Return the visitors happiness in float 0-1 range.
     */
    float getOverallHappiness();

    /**
     * @return Return the time since the game started in sec.
     */
    int getTime();

    /**
     * @param scale The amount witch will be multiplied with the deltaTime, 0 is freeze, 1 is default, 5 max
     */
    void setTimeScale(float scale);


    /**
     * @return Return the world builder.
     */
    Builder getWorldBuilder();

    /**
     * @return Return the world statistics.
     */
    Statistics getStatistics();
}
