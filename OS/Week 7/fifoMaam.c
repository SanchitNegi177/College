#include <stdio.h>
#include <stdbool.h>
#include <string.h>
struct PageTable
{
    int frame_no;
    bool valid;
};
bool isPagePresent(struct PageTable PT[], int page, int n)
{
    if (PT[page].valid == 1)
        return true;
    return false;
}
void updatePageTable(struct PageTable PT[], int page, int fr_no, int status)
{
    PT[page].valid = status;
    PT[page].frame_no = fr_no;
}

void printFrameContents(int frame[], int no_of_frames)
{
    for (int i = 0; i < no_of_frames; i++)
        printf("%d ", frame[i]);
    printf("\n");
}

int main()
{
    int i, n, no_of_frames, page_fault = 0, current = 0;
    bool flag = false;
    printf("\n Enter the no. of pages:\n");
    scanf("%d", &n);
    
    int reference_string[n];
    printf("\n Enter the reference string(different page numbers) :\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &reference_string[i]);
    printf("\n Enter the no. of frames you want to give to the process :");
    scanf("%d", &no_of_frames);

    // create frame array to store the pages at different point of times
    int frame[no_of_frames];
    memset(frame, -1, no_of_frames * sizeof(int));

    struct PageTable PT[50];

    for (int i = 0; i < 50; i++)
        PT[i].valid = 0;

    printf("\n****The Contents inside the Frame array at different time:****\n");
    for (int i = 0; i < n; i++)
    {
        // search the ith page in all allocated frames
        if (!(isPagePresent(PT, reference_string[i], n)))
        {
            page_fault++; // Increase the count of page fault
            if (flag == false && current < no_of_frames)
            {
                frame[current] = reference_string[i];
                printFrameContents(frame, no_of_frames);
                updatePageTable(PT, reference_string[i], current, 1);
                current = current + 1;
                if (current == no_of_frames)
                {
                    current = 0;
                    flag = true; // so that we do not come to this if block again
                }
            }

            else
            // frame are full , APPLY FIFO
            {
                // find the FIFO page (victim page) to replace;
                // The page pointed by current_head is FIFO page (victim page), so need to
                // mark that page as INVALID as in Page Table
                // set invalid frame no as -1 or anything ( as function needs this parameter),
                updatePageTable(PT, frame[current], -1, 0);
                frame[current] = reference_string[i];
                printFrameContents(frame, no_of_frames);
                updatePageTable(PT, reference_string[i], current, 1);
                current = (current + 1) % no_of_frames;
            }
        } // end of outer if
    } // end of for loop

    printf("\nTotal No. of Page Faults = %d\n", page_fault);
    printf("\nPage Fault ratio = %.2f\n", (float)page_fault / n);
    printf("\nPage Hit Ratio = %.2f\n", (float)(n - page_fault) / n);
    return 0;
}