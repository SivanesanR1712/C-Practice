#include <stdio.h>
#include <stdint.h>

static void print_bits32(uint32_t x)
{
    int i;
    for (i = 31; i >= 0; i--) {
        putchar((x & (1u << i)) ? '1' : '0');
        if (i % 4 == 0) putchar(' ');
    }
    putchar('\n');
}

static int is_valid_bitpos(int pos)
{
    if (pos < 0 || pos > 31) return 0;
    return 1;
}

static uint32_t set_bit(uint32_t x, int pos)   { return x |  (1u << pos); }
static uint32_t clear_bit(uint32_t x, int pos) { return x & ~(1u << pos); }
static uint32_t toggle_bit(uint32_t x, int pos){ return x ^  (1u << pos); }

static void show_bytes_le(uint32_t x)
{
    unsigned char *p = (unsigned char *)&x;
    printf("Bytes (memory order on this PC): %02X %02X %02X %02X\n",
           p[0], p[1], p[2], p[3]);
}

static uint32_t reverse_bits32(uint32_t x)
{
    uint32_t r = 0;
    int i;
    for (i = 0; i < 32; i++) {
        r <<= 1;
        r |= (x & 1u);
        x >>= 1;
    }
    return r;
}

int main(void)
{
    uint32_t x;
    int choice;

    printf("Enter a 32-bit unsigned number (0 to 4294967295): ");
    if (scanf("%u", &x) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    while (1) {
        printf("\nCurrent value: %u (0x%08X)\n", x, x);
        printf("Bits: ");
        print_bits32(x);

        printf("\nMenu:\n");
        printf("1. Set a bit\n");
        printf("2. Clear a bit\n");
        printf("3. Toggle a bit\n");
        printf("4. Check if a bit is 1 or 0\n");
        printf("5. Show bytes\n");
        printf("6. Reverse all bits\n");
        printf("7. Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid choice input.\n");
            return 1;
        }

        if (choice == 7) {
            printf("Exiting.\n");
            break;
        }

        switch (choice) {
            case 1:
            case 2:
            case 3:
            case 4: {
                int pos;
                printf("Enter bit position (0 to 31): ");
                if (scanf("%d", &pos) != 1) {
                    printf("Invalid position input.\n");
                    return 1;
                }
                if (!is_valid_bitpos(pos)) {
                    printf("Position must be 0..31.\n");
                    break;
                }

                if (choice == 1) {
                    x = set_bit(x, pos);
                    printf("Bit %d set.\n", pos);
                } else if (choice == 2) {
                    x = clear_bit(x, pos);
                    printf("Bit %d cleared.\n", pos);
                } else if (choice == 3) {
                    x = toggle_bit(x, pos);
                    printf("Bit %d toggled.\n", pos);
                } else {
                    int bit = (x >> pos) & 1u;
                    printf("Bit %d is %d.\n", pos, bit);
                }
                break;
            }

            case 5:
                show_bytes_le(x);
                break;

            case 6: {
                uint32_t r = reverse_bits32(x);
                printf("Reversed bits value: %u (0x%08X)\n", r, r);
                x = r;
                break;
            }

            default:
                printf("Choose 1 to 7.\n");
                break;
        }
    }

    return 0;
}
