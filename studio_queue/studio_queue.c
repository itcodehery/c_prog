#include <stdio.h>
#define LIN_QUEUE_SIZE 10
#define CIR_QUEUE_SIZE 5
#define PRI_QUEUE_SIZE 8

// The main queues
int l_queue[LIN_QUEUE_SIZE];
int c_queue[CIR_QUEUE_SIZE];
int p_queue[PRI_QUEUE_SIZE];

// nav pointers
int l_front = -1, l_rear = -1;
int c_front = -1, c_rear = -1;
int p_front = -1, p_rear = -1;

// 1. Linear Queue Functions
void l_enq() {
  int id;
  if (l_rear == LIN_QUEUE_SIZE - 1) {
    printf("\nSchedule is full for the day!");
    return;
  }
  printf("\nEnter the artist ID to add to schedule: ");
  scanf("%d", &id);
  if (l_front == -1) {
    l_front = 0;
  }
  l_rear++;
  l_queue[l_rear] = id;
  printf("\nAdding Artist #%d to the schedule.", id);
}

void l_deq() {
  if (l_front == -1 || l_front > l_rear) {
    printf("\nSchedule is empty!");
    return;
  }
  printf("\nArtist #%d has completed their recording session!",
         l_queue[l_front]);
  l_front++;
  if (l_front > l_rear) {
    l_front = -1;
    l_rear = -1;
  }
}

void l_peek() {
  if (l_front == -1 || l_front > l_rear) {
    printf("\nNo artists currently in the schedule.");
    return;
  }
  printf("\nArtist currently recording: #%d", l_queue[l_front]);
}

void l_display() {
  if (l_front == -1) {
    printf("\nSchedule is empty!");
    return;
  }
  printf("\nShowing all artists in line for recording:\n");
  for (int i = l_front; i <= l_rear; i++) {
    printf("Artist #%d\n", l_queue[i]);
  }
}

void l_main_loop() {
  int ch = 0;
  while (ch != 5) {
    printf("\n----------------");
    printf("\nRecording Session Queue");
    printf("\n----------------");
    printf("\n1. Add new Artist to Line");
    printf("\n2. End current artist's session");
    printf("\n3. Check next artist in line");
    printf("\n4. Show all artists (ID) in line");
    printf("\n5. Exit");
    printf("\nEnter your choice: ");
    scanf("%d", &ch);
    switch (ch) {
    case 1:
      l_enq();
      break;
    case 2:
      l_deq();
      break;
    case 3:
      l_peek();
      break;
    case 4:
      l_display();
      break;
    case 5:
      printf("\nExiting Recording Session Manager...");
      break;
    default:
      printf("\nInvalid choice!");
      break;
    }
  }
}

// 2. Circular Queue Functions
void c_enq() {
  int loop_id;
  if ((c_rear + 1) % CIR_QUEUE_SIZE == c_front) {
    printf("\nSound Effects Buffer is full!");
    return;
  }
  printf("\nEnter the ID of the loop to add to the buffer: ");
  scanf("%d", &loop_id);
  if (c_front == -1) {
    c_front = 0;
  }
  c_rear = (c_rear + 1) % CIR_QUEUE_SIZE;
  c_queue[c_rear] = loop_id;
  printf("\nLoop #%d added to the buffer.", loop_id);
}

void c_deq() {
  if (c_front == -1) {
    printf("\nBuffer is empty!");
    return;
  }
  printf("\nLoop #%d is removed from the buffer.", c_queue[c_front]);
  if (c_front == c_rear) {
    c_front = -1;
    c_rear = -1;
  } else {
    c_front = (c_front + 1) % CIR_QUEUE_SIZE;
  }
}

void c_peek() {
  if (c_front == -1) {
    printf("\nBuffer is empty!");
    return;
  }
  printf("\nCurrently playing loop ID: #%d", c_queue[c_front]);
}

void c_display() {
  if (c_front == -1) {
    printf("\nBuffer is empty!");
    return;
  }
  printf("\nLoop IDs in buffer: \n");
  int i = c_front;
  while (1) {
    printf("Loop #%d\n", c_queue[i]);
    if (i == c_rear) {
      break;
    }
    i = (i + 1) % CIR_QUEUE_SIZE;
  }
}

void c_main_loop() {
  int ch = 0;
  while (ch != 5) {
    printf("\n----------------");
    printf("\nSound Effects Buffer");
    printf("\n----------------");
    printf("\n1. Add loop (ID) to buffer");
    printf("\n2. Remove loop from buffer");
    printf("\n3. Show currently playing loop ID");
    printf("\n4. Show all loop IDs");
    printf("\n5. Exit");
    printf("\nEnter your choice: ");
    scanf("%d", &ch);
    switch (ch) {
    case 1:
      c_enq();
      break;
    case 2:
      c_deq();
      break;
    case 3:
      c_peek();
      break;
    case 4:
      c_display();
      break;
    case 5:
      printf("\nExiting Sound Effects Buffer Manager...");
      break;
    default:
      printf("\nInvalid choice!");
      break;
    }
  }
}

// 3. Priority Queue Functions
void p_enq() {
  int track_id;
  if (p_rear == PRI_QUEUE_SIZE - 1) {
    printf("\nAuto-Mixer is full!");
    return;
  }
  printf("\nEnter the Track ID (priority) to push to Auto-Mixer: ");
  scanf("%d", &track_id);

  if (p_front == -1) {
    p_front = 0;
    p_rear = 0;
    p_queue[p_rear] = track_id;
  } else {
    int i;
    for (i = p_rear; i >= p_front && p_queue[i] > track_id; i--) {
      p_queue[i + 1] = p_queue[i];
    }
    p_queue[i + 1] = track_id;
    p_rear++;
  }
  printf("Track #%d pushed to the Auto-Mixer.", track_id);
}

void p_deq() {
  if (p_front == -1 || p_front > p_rear) {
    printf("\nAuto-Mixer is empty!");
    return;
  }
  printf("\nProcessing high-priority Track #%d.", p_queue[p_front]);
  p_front++;
  if (p_front > p_rear) {
    p_front = -1;
    p_rear = -1;
  }
}

void p_peek() {
  if (p_front == -1 || p_front > p_rear) {
    printf("\nAuto-Mixer is empty!");
    return;
  }
  printf("\nNext track to be processed: #%d", p_queue[p_front]);
}

void p_display() {
  if (p_front == -1 || p_front > p_rear) {
    printf("\nAuto-Mixer is empty!");
    return;
  }
  printf("\nTracks in Auto-Mixer (by priority):\n");
  for (int i = p_front; i <= p_rear; i++) {
    printf("Track #%d\n", p_queue[i]);
  }
}

void p_show_priorities() {
  printf("\n--- Track Priorities ---");
  printf("\nLower value means higher priority.");
  printf("\n1: Vocals");
  printf("\n2: Drums/Bass");
  printf("\n3: Guitar/Keys");
  printf("\n4: Background Vocals");
  printf("\n5: FX");
  printf("\n------------------------\n");
}

void p_main_loop() {
  int ch = 0;
  while (ch != 5) {
    printf("\n----------------");
    printf("\nAuto-Mixer System");
    printf("\n----------------");
    printf("\n0. Show Priorities");
    printf("\n1. Push Track to Auto-Mixer");
    printf("\n2. Process high-priority Track");
    printf("\n3. Check next track");
    printf("\n4. Show all tracks");
    printf("\n5. Exit");
    printf("\nEnter your choice: ");
    scanf("%d", &ch);
    switch (ch) {
    case 0:
      p_show_priorities();
      break;
    case 1:
      p_enq();
      break;
    case 2:
      p_deq();
      break;
    case 3:
      p_peek();
      break;
    case 4:
      p_display();
      break;
    case 5:
      printf("\nExiting Auto-Mixer System...");
      break;
    default:
      printf("\nInvalid Choice!");
      break;
    }
  }
}

// Main
int main() {
  int ch = 0;
  while (ch != 4) {
    printf("\n\n----------------------");
    printf("\nMusic Studio Manager");
    printf("\n----------------------");
    printf("\nWhat would you like to manage?");
    printf("\n1. Recording Session Queue");
    printf("\n2. Sound Effect Loop Buffer");
    printf("\n3. Auto-Mixer System");
    printf("\n4. Exit");
    printf("\n----------------------");
    printf("\nYour choice: ");
    scanf("%d", &ch);
    switch (ch) {
    case 1:
      l_main_loop();
      break;
    case 2:
      c_main_loop();
      break;
    case 3:
      p_main_loop();
      break;
    default:
      return 0;
    }
  }
  return 0;
}
