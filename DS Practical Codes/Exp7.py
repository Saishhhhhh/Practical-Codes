# %% [markdown]
# ## Lab Assignment 7 
# 
# Title: Text Analytics 
#  
# PROBLEM STATEMENT: 
# 1. Extract Sample document and apply following document preprocessing methods: Tokenization, POS 
# Tagging, stop words removal, Stemming and Lemmatization. 
# 2. Create representation of documents by calculating Term Frequency and Inverse Document Frequency.

# %%
# Exp7.py
# !pip install nltk scikit-learn
import nltk
from nltk.tokenize import word_tokenize, sent_tokenize
from nltk.corpus import stopwords
from nltk.stem import PorterStemmer, WordNetLemmatizer
from nltk import pos_tag

from sklearn.feature_extraction.text import CountVectorizer
from sklearn.feature_extraction.text import TfidfVectorizer

# %%
nltk.download('punkt')
nltk.download('stopwords')
nltk.download('wordnet')
nltk.download('averaged_perceptron_tagger')

# %%
text = """Artificial Intelligence is transforming the world.
Machine learning and deep learning are important branches of AI.
Text analytics helps in extracting useful insights from textual data."""

# %%
print("Original Document:\n")
print(text)

# %%
sent_tokens = sent_tokenize(text)
word_tokens = word_tokenize(text)

print("Sentence Tokens:", sent_tokens)
print("Word Tokens:", word_tokens)

# %%
stop_words = set(stopwords.words('english'))

filtered_words = [w for w in word_tokens if w.lower() not in stop_words]

print("After Stopword Removal:", filtered_words)

# %%
pos_tags = pos_tag(filtered_words)

print("POS Tags:", pos_tags)

# %%
stemmer = PorterStemmer()

stemmed_words = [stemmer.stem(w) for w in filtered_words]

print("Stemmed Words:", stemmed_words)

# %%
lemmatizer = WordNetLemmatizer()

lemmatized_words = [lemmatizer.lemmatize(w) for w in filtered_words]

print("Lemmatized Words:", lemmatized_words)

# %%
documents = [text]

cv = CountVectorizer()

tf_matrix = cv.fit_transform(documents)

print("Term Frequency Matrix:\n", tf_matrix.toarray())
print("TF Feature Names:", cv.get_feature_names_out())

# %%
documents = [text]

vectorizer = TfidfVectorizer()
tfidf_matrix = vectorizer.fit_transform(documents)

print("Feature Names:", vectorizer.get_feature_names_out())
print("TF-IDF Matrix:\n", tfidf_matrix.toarray())


