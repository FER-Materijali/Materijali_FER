# Duboko učenje
## Treća laboratorijska vježba - Analiza klasifikacije sentimenta

### Priprema

Ova vježba je specifična po tome što nema `data` direktorij. Ono što je potrebno prije pokretanja je sljedeće:

- napraviti `LAB3/data` direktorij
- preuzeti skup podataka s [ove poveznice](https://github.com/dlunizg/dlunizg.github.io/tree/master/data/lab3)
- preimenovati podatke:
   - `sst_test_raw.csv` -> `test.csv`
   - `sst_train_raw.csv` -> `train.csv`
   - `sst_valid_raw.csv` -> `val.csv`
- preuzeti vektorske reprezentacije s [ove poveznice](https://drive.google.com/file/d/12mA5QEN4nFcxfEzOS8Nqj5afOmkuclc7)
- preimenovati datoteku `set_glove_6b_300d.txt` u `embeddings_300-d.txt`
- premjestiti sve preuzete datoteke u `LAB3/data`

Nakon toga slobodno možete pokrenuti vježbu. Ako želite ponovno trenirati neke od zadataka, ne zaboravite postaviti zastavice `run_task_X` na `True`, gdje je X broj zadatka. Ove varijable nalaze se u sekciji **Pokretanje zadataka**.
