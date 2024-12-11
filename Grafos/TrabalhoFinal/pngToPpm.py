from PIL import Image
import sys

def convert_png_to_ppm(input_file, output_file):
    """
    Converts a PNG file to PPM format.

    :param input_file: Path to the input PNG file.
    :param output_file: Path to the output PPM file.
    """
    try:
        # Open the PNG image
        with Image.open(input_file) as img:
            # Save it as PPM
            img.save(output_file, 'PPM')

        print(f"Successfully converted {input_file} to {output_file}")

    except Exception as e:
        print(f"Error converting {input_file}: {e}")

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Usage: python3 png_to_ppm.py <input_file.png> <output_file.ppm>")
        sys.exit(1)

    input_path = sys.argv[1]
    output_path = sys.argv[2]

    if not input_path.lower().endswith('.png'):
        print("The input file does not appear to be a PNG file.")
        sys.exit(1)

    if not output_path.lower().endswith('.ppm'):
        output_path += '.ppm'

    convert_png_to_ppm(input_path, output_path)
