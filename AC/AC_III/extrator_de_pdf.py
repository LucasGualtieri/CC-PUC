from PyPDF2 import PdfReader, PdfWriter

def extract_pages(input_pdf, output_pdf, start_page, end_page):
    reader = PdfReader(input_pdf)
    writer = PdfWriter()

    for page_num in range(start_page - 1, end_page):
        writer.add_page(reader.pages[page_num])

    with open(output_pdf, "wb") as output_file:
        writer.write(output_file)

extract_pages("1-ACIII-Slides.pdf", "Arquiteturas-Paralelas.pdf", 139, 168)
