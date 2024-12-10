from PIL import Image
import sys

def convert_ppm_to_png(input_file, output_file):
    """
    Converts a PPM file to PNG format.

    :param input_file: Path to the input PPM file.
    :param output_file: Path to the output PNG file.
    """
    try:
        # Open the PPM image
        with Image.open(input_file) as img:
            # Save it as PNG
            img.save(output_file, 'PNG')

        print(f"Successfully converted {input_file} to {output_file}")

    except Exception as e:
        print(f"Error converting {input_file}: {e}")

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Usage: python3 ppm_to_png.py <input_file.ppm> <output_file.png>")
        sys.exit(1)

    input_path = sys.argv[1]
    output_path = sys.argv[2]

    if not input_path.lower().endswith('.ppm'):
        print("The input file does not appear to be a PPM file.")
        sys.exit(1)

    if not output_path.lower().endswith('.png'):
        output_path += '.png'

    convert_ppm_to_png(input_path, output_path)

